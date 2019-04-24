/* According to POSIX.1-2001, POSIX.1-2008 */
#include <sys/select.h>
#include <signal.h>
/* According to earlier standards */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <thread>

static volatile int punt;
static volatile bool succ = false;
static void sig_handler(int sig)
{
    punt = 1;
}

static void succ_sig_handler(int sig)
{
  succ = true;
}

int main(int argc, char const *argv[]) {
  struct timeval timeout = {10,0};
  int rc;

  signal(SIGCHLD, sig_handler);
  signal(SIGUSR1, succ_sig_handler);

  pid_t p = fork();
  ///////////////////////////
  // parent
  ///////////////////////////
  if(p > 0){
    std::cout << "parent pid" << getpid() << std::endl;
    rc = select(0, NULL,NULL,NULL, &timeout );
    if (rc == 0) {
      // timed out, kill child process
      kill(p, SIGKILL);
      std::cout << "child time out " << std::endl;
    } else if (punt) {
      //child terminated
      std::cout << "child terminated" << std::endl;
    } else if (succ){
      std::cout << "child did not succ finished" << std::endl;
    }
  } else {
    ///////////////////////////
    // chile
    ///////////////////////////
    //do some work
    int count = 0;
    while(count < 100000) count++;
    //std::this_thread::sleep_for (std::chrono::seconds(60));
    std::cout << "child parent pid" << getppid() << std::endl;
    kill(getppid(), SIGUSR1);
  }

}
