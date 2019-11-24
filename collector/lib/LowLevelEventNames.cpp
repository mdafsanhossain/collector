#include "LowLevelEventNames.h"

#include "StringUtil.h"

namespace collector {

LowLevelEventNames::LowLevelEventNames() {
    // Created by copying event list and applying regex replace
    // `(PPME_[A-Z0-9_]+)\s*=.*` => `_E($1)`
#   define _E(name) names_[name] = #name;
    _E(PPME_GENERIC_E)
    _E(PPME_GENERIC_X)
    _E(PPME_SYSCALL_OPEN_E)
    _E(PPME_SYSCALL_OPEN_X)
    _E(PPME_SYSCALL_CLOSE_E)
    _E(PPME_SYSCALL_CLOSE_X)
    _E(PPME_SYSCALL_READ_E)
    _E(PPME_SYSCALL_READ_X)
    _E(PPME_SYSCALL_WRITE_E)
    _E(PPME_SYSCALL_WRITE_X)
    _E(PPME_SYSCALL_BRK_1_E)
    _E(PPME_SYSCALL_BRK_1_X)
    _E(PPME_SYSCALL_EXECVE_8_E)
    _E(PPME_SYSCALL_EXECVE_8_X)
    _E(PPME_SYSCALL_CLONE_11_E)
    _E(PPME_SYSCALL_CLONE_11_X)
    _E(PPME_PROCEXIT_E)
    _E(PPME_PROCEXIT_X)
    _E(PPME_SOCKET_SOCKET_E)
    _E(PPME_SOCKET_SOCKET_X)
    _E(PPME_SOCKET_BIND_E)
    _E(PPME_SOCKET_BIND_X)
    _E(PPME_SOCKET_CONNECT_E)
    _E(PPME_SOCKET_CONNECT_X)
    _E(PPME_SOCKET_LISTEN_E)
    _E(PPME_SOCKET_LISTEN_X)
    _E(PPME_SOCKET_ACCEPT_E)
    _E(PPME_SOCKET_ACCEPT_X)
    _E(PPME_SOCKET_SEND_E)
    _E(PPME_SOCKET_SEND_X)
    _E(PPME_SOCKET_SENDTO_E)
    _E(PPME_SOCKET_SENDTO_X)
    _E(PPME_SOCKET_RECV_E)
    _E(PPME_SOCKET_RECV_X)
    _E(PPME_SOCKET_RECVFROM_E)
    _E(PPME_SOCKET_RECVFROM_X)
    _E(PPME_SOCKET_SHUTDOWN_E)
    _E(PPME_SOCKET_SHUTDOWN_X)
    _E(PPME_SOCKET_GETSOCKNAME_E)
    _E(PPME_SOCKET_GETSOCKNAME_X)
    _E(PPME_SOCKET_GETPEERNAME_E)
    _E(PPME_SOCKET_GETPEERNAME_X)
    _E(PPME_SOCKET_SOCKETPAIR_E)
    _E(PPME_SOCKET_SOCKETPAIR_X)
    _E(PPME_SOCKET_SETSOCKOPT_E)
    _E(PPME_SOCKET_SETSOCKOPT_X)
    _E(PPME_SOCKET_GETSOCKOPT_E)
    _E(PPME_SOCKET_GETSOCKOPT_X)
    _E(PPME_SOCKET_SENDMSG_E)
    _E(PPME_SOCKET_SENDMSG_X)
    _E(PPME_SOCKET_SENDMMSG_E)
    _E(PPME_SOCKET_SENDMMSG_X)
    _E(PPME_SOCKET_RECVMSG_E)
    _E(PPME_SOCKET_RECVMSG_X)
    _E(PPME_SOCKET_RECVMMSG_E)
    _E(PPME_SOCKET_RECVMMSG_X)
    _E(PPME_SOCKET_ACCEPT4_E)
    _E(PPME_SOCKET_ACCEPT4_X)
    _E(PPME_SYSCALL_CREAT_E)
    _E(PPME_SYSCALL_CREAT_X)
    _E(PPME_SYSCALL_PIPE_E)
    _E(PPME_SYSCALL_PIPE_X)
    _E(PPME_SYSCALL_EVENTFD_E)
    _E(PPME_SYSCALL_EVENTFD_X)
    _E(PPME_SYSCALL_FUTEX_E)
    _E(PPME_SYSCALL_FUTEX_X)
    _E(PPME_SYSCALL_STAT_E)
    _E(PPME_SYSCALL_STAT_X)
    _E(PPME_SYSCALL_LSTAT_E)
    _E(PPME_SYSCALL_LSTAT_X)
    _E(PPME_SYSCALL_FSTAT_E)
    _E(PPME_SYSCALL_FSTAT_X)
    _E(PPME_SYSCALL_STAT64_E)
    _E(PPME_SYSCALL_STAT64_X)
    _E(PPME_SYSCALL_LSTAT64_E)
    _E(PPME_SYSCALL_LSTAT64_X)
    _E(PPME_SYSCALL_FSTAT64_E)
    _E(PPME_SYSCALL_FSTAT64_X)
    _E(PPME_SYSCALL_EPOLLWAIT_E)
    _E(PPME_SYSCALL_EPOLLWAIT_X)
    _E(PPME_SYSCALL_POLL_E)
    _E(PPME_SYSCALL_POLL_X)
    _E(PPME_SYSCALL_SELECT_E)
    _E(PPME_SYSCALL_SELECT_X)
    _E(PPME_SYSCALL_NEWSELECT_E)
    _E(PPME_SYSCALL_NEWSELECT_X)
    _E(PPME_SYSCALL_LSEEK_E)
    _E(PPME_SYSCALL_LSEEK_X)
    _E(PPME_SYSCALL_LLSEEK_E)
    _E(PPME_SYSCALL_LLSEEK_X)
    _E(PPME_SYSCALL_IOCTL_2_E)
    _E(PPME_SYSCALL_IOCTL_2_X)
    _E(PPME_SYSCALL_GETCWD_E)
    _E(PPME_SYSCALL_GETCWD_X)
    _E(PPME_SYSCALL_CHDIR_E)
    _E(PPME_SYSCALL_CHDIR_X)
    _E(PPME_SYSCALL_FCHDIR_E)
    _E(PPME_SYSCALL_FCHDIR_X)
    _E(PPME_SYSCALL_MKDIR_E)
    _E(PPME_SYSCALL_MKDIR_X)
    _E(PPME_SYSCALL_RMDIR_E)
    _E(PPME_SYSCALL_RMDIR_X)
    _E(PPME_SYSCALL_OPENAT_E)
    _E(PPME_SYSCALL_OPENAT_X)
    _E(PPME_SYSCALL_LINK_E)
    _E(PPME_SYSCALL_LINK_X)
    _E(PPME_SYSCALL_LINKAT_E)
    _E(PPME_SYSCALL_LINKAT_X)
    _E(PPME_SYSCALL_UNLINK_E)
    _E(PPME_SYSCALL_UNLINK_X)
    _E(PPME_SYSCALL_UNLINKAT_E)
    _E(PPME_SYSCALL_UNLINKAT_X)
    _E(PPME_SYSCALL_PREAD_E)
    _E(PPME_SYSCALL_PREAD_X)
    _E(PPME_SYSCALL_PWRITE_E)
    _E(PPME_SYSCALL_PWRITE_X)
    _E(PPME_SYSCALL_READV_E)
    _E(PPME_SYSCALL_READV_X)
    _E(PPME_SYSCALL_WRITEV_E)
    _E(PPME_SYSCALL_WRITEV_X)
    _E(PPME_SYSCALL_PREADV_E)
    _E(PPME_SYSCALL_PREADV_X)
    _E(PPME_SYSCALL_PWRITEV_E)
    _E(PPME_SYSCALL_PWRITEV_X)
    _E(PPME_SYSCALL_DUP_E)
    _E(PPME_SYSCALL_DUP_X)
    _E(PPME_SYSCALL_SIGNALFD_E)
    _E(PPME_SYSCALL_SIGNALFD_X)
    _E(PPME_SYSCALL_KILL_E)
    _E(PPME_SYSCALL_KILL_X)
    _E(PPME_SYSCALL_TKILL_E)
    _E(PPME_SYSCALL_TKILL_X)
    _E(PPME_SYSCALL_TGKILL_E)
    _E(PPME_SYSCALL_TGKILL_X)
    _E(PPME_SYSCALL_NANOSLEEP_E)
    _E(PPME_SYSCALL_NANOSLEEP_X)
    _E(PPME_SYSCALL_TIMERFD_CREATE_E)
    _E(PPME_SYSCALL_TIMERFD_CREATE_X)
    _E(PPME_SYSCALL_INOTIFY_INIT_E)
    _E(PPME_SYSCALL_INOTIFY_INIT_X)
    _E(PPME_SYSCALL_GETRLIMIT_E)
    _E(PPME_SYSCALL_GETRLIMIT_X)
    _E(PPME_SYSCALL_SETRLIMIT_E)
    _E(PPME_SYSCALL_SETRLIMIT_X)
    _E(PPME_SYSCALL_PRLIMIT_E)
    _E(PPME_SYSCALL_PRLIMIT_X)
    _E(PPME_SCHEDSWITCH_1_E)
    _E(PPME_SCHEDSWITCH_1_X)
    _E(PPME_DROP_E)
    _E(PPME_DROP_X)
    _E(PPME_SYSCALL_FCNTL_E)
    _E(PPME_SYSCALL_FCNTL_X)
    _E(PPME_SCHEDSWITCH_6_E)
    _E(PPME_SCHEDSWITCH_6_X)
    _E(PPME_SYSCALL_EXECVE_13_E)
    _E(PPME_SYSCALL_EXECVE_13_X)
    _E(PPME_SYSCALL_CLONE_16_E)
    _E(PPME_SYSCALL_CLONE_16_X)
    _E(PPME_SYSCALL_BRK_4_E)
    _E(PPME_SYSCALL_BRK_4_X)
    _E(PPME_SYSCALL_MMAP_E)
    _E(PPME_SYSCALL_MMAP_X)
    _E(PPME_SYSCALL_MMAP2_E)
    _E(PPME_SYSCALL_MMAP2_X)
    _E(PPME_SYSCALL_MUNMAP_E)
    _E(PPME_SYSCALL_MUNMAP_X)
    _E(PPME_SYSCALL_SPLICE_E)
    _E(PPME_SYSCALL_SPLICE_X)
    _E(PPME_SYSCALL_PTRACE_E)
    _E(PPME_SYSCALL_PTRACE_X)
    _E(PPME_SYSCALL_IOCTL_3_E)
    _E(PPME_SYSCALL_IOCTL_3_X)
    _E(PPME_SYSCALL_EXECVE_14_E)
    _E(PPME_SYSCALL_EXECVE_14_X)
    _E(PPME_SYSCALL_RENAME_E)
    _E(PPME_SYSCALL_RENAME_X)
    _E(PPME_SYSCALL_RENAMEAT_E)
    _E(PPME_SYSCALL_RENAMEAT_X)
    _E(PPME_SYSCALL_SYMLINK_E)
    _E(PPME_SYSCALL_SYMLINK_X)
    _E(PPME_SYSCALL_SYMLINKAT_E)
    _E(PPME_SYSCALL_SYMLINKAT_X)
    _E(PPME_SYSCALL_FORK_E)
    _E(PPME_SYSCALL_FORK_X)
    _E(PPME_SYSCALL_VFORK_E)
    _E(PPME_SYSCALL_VFORK_X)
    _E(PPME_PROCEXIT_1_E)
    _E(PPME_PROCEXIT_1_X)
    _E(PPME_SYSCALL_SENDFILE_E)
    _E(PPME_SYSCALL_SENDFILE_X)
    _E(PPME_SYSCALL_QUOTACTL_E)
    _E(PPME_SYSCALL_QUOTACTL_X)
    _E(PPME_SYSCALL_SETRESUID_E)
    _E(PPME_SYSCALL_SETRESUID_X)
    _E(PPME_SYSCALL_SETRESGID_E)
    _E(PPME_SYSCALL_SETRESGID_X)
    _E(PPME_SYSDIGEVENT_E)
    _E(PPME_SYSDIGEVENT_X)
    _E(PPME_SYSCALL_SETUID_E)
    _E(PPME_SYSCALL_SETUID_X)
    _E(PPME_SYSCALL_SETGID_E)
    _E(PPME_SYSCALL_SETGID_X)
    _E(PPME_SYSCALL_GETUID_E)
    _E(PPME_SYSCALL_GETUID_X)
    _E(PPME_SYSCALL_GETEUID_E)
    _E(PPME_SYSCALL_GETEUID_X)
    _E(PPME_SYSCALL_GETGID_E)
    _E(PPME_SYSCALL_GETGID_X)
    _E(PPME_SYSCALL_GETEGID_E)
    _E(PPME_SYSCALL_GETEGID_X)
    _E(PPME_SYSCALL_GETRESUID_E)
    _E(PPME_SYSCALL_GETRESUID_X)
    _E(PPME_SYSCALL_GETRESGID_E)
    _E(PPME_SYSCALL_GETRESGID_X)
    _E(PPME_SYSCALL_EXECVE_15_E)
    _E(PPME_SYSCALL_EXECVE_15_X)
    _E(PPME_SYSCALL_CLONE_17_E)
    _E(PPME_SYSCALL_CLONE_17_X)
    _E(PPME_SYSCALL_FORK_17_E)
    _E(PPME_SYSCALL_FORK_17_X)
    _E(PPME_SYSCALL_VFORK_17_E)
    _E(PPME_SYSCALL_VFORK_17_X)
    _E(PPME_SYSCALL_CLONE_20_E)
    _E(PPME_SYSCALL_CLONE_20_X)
    _E(PPME_SYSCALL_FORK_20_E)
    _E(PPME_SYSCALL_FORK_20_X)
    _E(PPME_SYSCALL_VFORK_20_E)
    _E(PPME_SYSCALL_VFORK_20_X)
    _E(PPME_CONTAINER_E)
    _E(PPME_CONTAINER_X)
    _E(PPME_SYSCALL_EXECVE_16_E)
    _E(PPME_SYSCALL_EXECVE_16_X)
    _E(PPME_SIGNALDELIVER_E)
    _E(PPME_SIGNALDELIVER_X)
    _E(PPME_PROCINFO_E)
    _E(PPME_PROCINFO_X)
    _E(PPME_SYSCALL_GETDENTS_E)
    _E(PPME_SYSCALL_GETDENTS_X)
    _E(PPME_SYSCALL_GETDENTS64_E)
    _E(PPME_SYSCALL_GETDENTS64_X)
    _E(PPME_SYSCALL_SETNS_E)
    _E(PPME_SYSCALL_SETNS_X)
    _E(PPME_SYSCALL_FLOCK_E)
    _E(PPME_SYSCALL_FLOCK_X)
    _E(PPME_CPU_HOTPLUG_E)
    _E(PPME_CPU_HOTPLUG_X)
    _E(PPME_SOCKET_ACCEPT_5_E)
    _E(PPME_SOCKET_ACCEPT_5_X)
    _E(PPME_SOCKET_ACCEPT4_5_E)
    _E(PPME_SOCKET_ACCEPT4_5_X)
    _E(PPME_SYSCALL_SEMOP_E)
    _E(PPME_SYSCALL_SEMOP_X)
    _E(PPME_SYSCALL_SEMCTL_E)
    _E(PPME_SYSCALL_SEMCTL_X)
    _E(PPME_SYSCALL_PPOLL_E)
    _E(PPME_SYSCALL_PPOLL_X)
    _E(PPME_SYSCALL_MOUNT_E)
    _E(PPME_SYSCALL_MOUNT_X)
    _E(PPME_SYSCALL_UMOUNT_E)
    _E(PPME_SYSCALL_UMOUNT_X)
    _E(PPME_K8S_E)
    _E(PPME_K8S_X)
    _E(PPME_SYSCALL_SEMGET_E)
    _E(PPME_SYSCALL_SEMGET_X)
    _E(PPME_SYSCALL_ACCESS_E)
    _E(PPME_SYSCALL_ACCESS_X)
    _E(PPME_SYSCALL_CHROOT_E)
    _E(PPME_SYSCALL_CHROOT_X)
    _E(PPME_TRACER_E)
    _E(PPME_TRACER_X)
    _E(PPME_MESOS_E)
    _E(PPME_MESOS_X)
    _E(PPME_CONTAINER_JSON_E)
    _E(PPME_CONTAINER_JSON_X)
    _E(PPME_SYSCALL_SETSID_E)
    _E(PPME_SYSCALL_SETSID_X)
    _E(PPME_SYSCALL_MKDIR_2_E)
    _E(PPME_SYSCALL_MKDIR_2_X)
    _E(PPME_SYSCALL_RMDIR_2_E)
    _E(PPME_SYSCALL_RMDIR_2_X)
    _E(PPME_NOTIFICATION_E)
    _E(PPME_NOTIFICATION_X)
    _E(PPME_SYSCALL_EXECVE_17_E)
    _E(PPME_SYSCALL_EXECVE_17_X)
    _E(PPME_SYSCALL_UNSHARE_E)
    _E(PPME_SYSCALL_UNSHARE_X)
    _E(PPME_INFRASTRUCTURE_EVENT_E)
    _E(PPME_INFRASTRUCTURE_EVENT_X)
    _E(PPME_SYSCALL_EXECVE_18_E)
    _E(PPME_SYSCALL_EXECVE_18_X)
    _E(PPME_PAGE_FAULT_E)
    _E(PPME_PAGE_FAULT_X)
    _E(PPME_SYSCALL_EXECVE_19_E)
    _E(PPME_SYSCALL_EXECVE_19_X)
    _E(PPME_SYSCALL_SETPGID_E)
    _E(PPME_SYSCALL_SETPGID_X)
    _E(PPME_SYSCALL_BPF_E)
    _E(PPME_SYSCALL_BPF_X)
    _E(PPME_SYSCALL_SECCOMP_E)
    _E(PPME_SYSCALL_SECCOMP_X)
    _E(PPME_SYSCALL_UNLINK_2_E)
    _E(PPME_SYSCALL_UNLINK_2_X)
    _E(PPME_SYSCALL_UNLINKAT_2_E)
    _E(PPME_SYSCALL_UNLINKAT_2_X)
    _E(PPME_SYSCALL_MKDIRAT_E)
    _E(PPME_SYSCALL_MKDIRAT_X)
    _E(PPME_SYSCALL_OPENAT_2_E)
    _E(PPME_SYSCALL_OPENAT_2_X)
    _E(PPME_SYSCALL_LINK_2_E)
    _E(PPME_SYSCALL_LINK_2_X)
    _E(PPME_SYSCALL_LINKAT_2_E)
    _E(PPME_SYSCALL_LINKAT_2_X)
    _E(PPME_SYSCALL_FCHMODAT_E)
    _E(PPME_SYSCALL_FCHMODAT_X)
    _E(PPME_SYSCALL_CHMOD_E)
    _E(PPME_SYSCALL_CHMOD_X)
    _E(PPME_SYSCALL_FCHMOD_E)
    _E(PPME_SYSCALL_FCHMOD_X)
#   undef _E

    for (unsigned i = 0; i < names_.size(); i++) {
        auto& entry = names_[i];
        if (entry.empty()) {
            entry = StrCat("#", i);
        }
    }
}

const std::string& LowLevelEventNames::GetEventName(ppm_event_type event_type) const {
  static std::string invalid = "invalid";
  if (event_type < 0 || event_type >= PPM_EVENT_MAX) {
      return invalid;
  }
  return names_[event_type];
}

const LowLevelEventNames& LowLevelEventNames::GetInstance() {
    static auto* instance = new LowLevelEventNames();
    return *instance;
}

}  // namespace collector
