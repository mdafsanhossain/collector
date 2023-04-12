#include "SelfChecks.h"

#include <unistd.h>

#include <sys/wait.h>

#include "Logging.h"

namespace collector {

namespace self_checks {

const char* kSelfChecksExePath = "/usr/local/bin/self-checks";
const char* kSelfChecksName = "self-checks";

int start_self_check_process() {
  pid_t child = fork();
  int status = 0;

  switch (child) {
    case -1:
      CLOG(FATAL) << "Failed to fork self-check process";
      break;
    case 0: {
      // in the child process
      char* argv[2] = {(char*)kSelfChecksExePath, NULL};
      execve(kSelfChecksExePath, argv, NULL);

      // if execve fails for whatever reason, immediately exit
      // from this process
      exit(-1);
      break;
    }
    default:
      waitpid(child, &status, 0);
      CLOG(INFO) << "self-check (" << child << ") exitted with status: " << WEXITSTATUS(status);
      break;
  }

  return status;
}

}  // namespace self_checks

}  // namespace collector
