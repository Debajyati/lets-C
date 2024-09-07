#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* *
 * A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.
 * In the following code, parent finishes execution and exits while the child process is still executing and is called an orphan process now.
 * */

/* *
 * Similarly, the orphan process in Linux is adopted by a new process, which is mostly init process (pid=1). 
 * This is called re-parenting.
 * Reparenting is done by the kernel, when the kernel detects an orphan process in OS and assigns a new parent process.
 * The new parent process asks the kernel for cleaning of the PCB of the orphan process and the new parent waits till the child completes its execution.
 * */

int main(){
  pid_t child_pid;

  child_pid = fork();


  if(child_pid > 0){
    exit(0);     // Parent process exits immediately
  }
  else{
    sleep(60);   // Child process sleeps for 60 seconds
  }


  return 0;
}
