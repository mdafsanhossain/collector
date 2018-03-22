/** collector

A full notice with attributions is provided along with this source code.

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

* In addition, as a special exception, the copyright holders give
* permission to link the code of portions of this program with the
* OpenSSL library under certain conditions as described in each
* individual source file, and distribute linked combinations
* including the two.
* You must obey the GNU General Public License in all respects
* for all of the code used other than OpenSSL.  If you modify
* file(s) with this exception, you may extend this exception to your
* version of the file(s), but you are not obligated to do so.  If you
* do not wish to do so, delete this exception statement from your
* version.
*/

#include "SysdigService.h"

#include <linux/ioctl.h>

#include "libsinsp/wrapper.h"

#include "CollectorException.h"
#include "Logging.h"
#include "StdoutSignalWriter.h"
#include "SignalFormatter.h"

namespace collector {

constexpr char SysdigService::kModulePath[];
constexpr char SysdigService::kModuleName[];


void SysdigService::Init(const CollectorConfig& config) {
  if (inspector_ || chisel_) {
    throw CollectorException("Invalid state: SysdigService was already initialized");
  }

  inspector_.reset(new_inspector());
  inspector_->set_snaplen(config.snapLen);

  SignalWriterFactory factory;

  if (config.useKafka) {
    factory.SetupKafka(config.brokerList);
  }
  signal_writers_[SIGNAL_TYPE_FILE] = factory.CreateSignalWriter(config.fileSignalOutput);
  signal_writers_[SIGNAL_TYPE_PROCESS] = factory.CreateSignalWriter(config.processSignalOutput);
  signal_writers_[SIGNAL_TYPE_NETWORK] = factory.CreateSignalWriter(config.networkSignalOutput);

  SignalFormatterFactory fmtFactory;
  signal_formatter_[SIGNAL_TYPE_FILE] = fmtFactory.CreateSignalFormatter(config.fileSignalFormat, inspector_.get(), config.format);
  signal_formatter_[SIGNAL_TYPE_PROCESS] = fmtFactory.CreateSignalFormatter(config.processSignalFormat, inspector_.get(), config.format);
  signal_formatter_[SIGNAL_TYPE_NETWORK] = fmtFactory.CreateSignalFormatter(config.networkSignalFormat, inspector_.get(), config.format);

  chisel_.reset(new_chisel(inspector_.get(), config.chiselName.c_str()));

  classifier_.Init(config.processSyscalls);
  use_chisel_cache_ = config.useChiselCache;
}

bool SysdigService::FilterEvent(sinsp_evt* event) {
  if (!use_chisel_cache_) {
    return chisel_->process(event);
  }

  sinsp_threadinfo* tinfo = event->get_thread_info();
  if (tinfo == NULL) {
    return false;
  }

  auto pair = chisel_cache_.emplace(tinfo->m_container_id, false); 
  bool& chisel_result = pair.first->second;

  if (pair.second) {  // was newly inserted
    bool res = chisel_->process(event);
    if (chisel_cache_.size() > 1024) {
      CLOG(INFO) << "Flushing chisel cache";
      chisel_cache_.clear();
      return res;
    }
    chisel_result = res;
    if (!res && event->get_type() != PPME_PROCEXIT_1_E) {
      // Exclude container for this process at the kernel level, but do not issue an ioctl at process exit.
      if (!inspector_->ioctl(0, PPM_IOCTL_EXCLUDE_NS_OF_PID, reinterpret_cast<void*>(tinfo->m_pid))) {
        CLOG(WARNING) << "Failed ioctl: " << inspector_->getlasterr();
      }
    }
  } else {
    ++userspace_stats_.nChiselCacheHits;
  }

  return chisel_result;
}

SignalType SysdigService::GetNext(SafeBuffer* message_buffer, SafeBuffer* key_buffer) {
  sinsp_evt* event;
  auto res = inspector_->next(&event);
  if (res != SCAP_SUCCESS) return SIGNAL_TYPE_UNKNOWN;

  if (event->get_category() & EC_INTERNAL) return SIGNAL_TYPE_UNKNOWN;

  ++userspace_stats_.nUserspaceEvents;
  if (!FilterEvent(event)) {
    return SIGNAL_TYPE_UNKNOWN;
  }

  key_buffer->clear();
  SignalType signal_type = classifier_.Classify(key_buffer, event);
  if (signal_type == SIGNAL_TYPE_UNKNOWN) return SIGNAL_TYPE_UNKNOWN;
  message_buffer->clear();
  signal_formatter_[signal_type]->FormatSignal(message_buffer, event);
  return signal_type;
}

void SysdigService::RunForever(const std::atomic_bool& interrupt) {
  if (!inspector_ || !chisel_) {
    throw CollectorException("Invalid state: SysdigService was not initialized");
  }

  SafeBuffer message_buffer(kMessageBufferSize);
  SafeBuffer key_buffer(kKeyBufferSize);

  chisel_->on_init();
  inspector_->open("");
  chisel_->on_capture_start();

  {
    std::lock_guard<std::mutex> lock(running_mutex_);
    running_ = true;
  }

  while (!interrupt.load(std::memory_order_relaxed)) {
    SignalType signal_type = GetNext(&message_buffer, &key_buffer);
    auto& signal_writer = signal_writers_[signal_type];

    if (!signal_writer) {
      continue;
    }
    ++userspace_stats_.nFilteredEvents;

    bool success = signal_writer->WriteSignal(message_buffer, key_buffer);
    if (!success) {
      ++userspace_stats_.nKafkaSendFailures;
    }
  }
  chisel_->on_capture_end();
}

void SysdigService::CleanUp() {
  std::lock_guard<std::mutex> lock(running_mutex_);
  running_ = false;
  inspector_->close();
  chisel_.reset();
  inspector_.reset();
  for (auto& signal_writer : signal_writers_) {
    signal_writer.reset();
  }
}

bool SysdigService::GetStats(SysdigStats* stats) const {
  std::lock_guard<std::mutex> lock(running_mutex_);
  if (!running_ || !inspector_) return false;

  scap_stats kernel_stats;
  inspector_->get_capture_stats(&kernel_stats);
  *stats = userspace_stats_;
  stats->nEvents = kernel_stats.n_evts;
  stats->nDrops = kernel_stats.n_drops;
  stats->nPreemptions = kernel_stats.n_preemptions;

  return true;
}

}  // namespace collector
