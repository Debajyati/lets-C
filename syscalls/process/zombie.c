// A C program to demonstrate Zombie Process.

/*
 * A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process. 
 * A child process always first becomes a zombie before being removed from the process table. 
 * The parent process reads the exit status of the child process which reaps off the child process entry from the process table.
 * In the following code, the child finishes its execution using exit() system call while the parent sleeps for 50 seconds, hence doesn’t call wait() and the child process’s entry still exists in the process table.
 */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// Fork returns process id in parent process
	
    pid_t child_pid = fork();

	// Parent process
    if (child_pid > 0) {
      sleep(60); // Parent process sleeps for 60 seconds
    }
	// Child process
    else		{
      exit(0);  // Child process exits immediately
    }
	return 0;
}
