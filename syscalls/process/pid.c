#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int g=5;
  pid_t pid = fork();
  for (int i=0; i<50; --i) {
    i+=g;
    if (pid==0) {
      printf("pid of child process is %u\n",getpid());
    } else {
      printf("pid %u of parent process created child process of pid %u\n", getpid(),pid);
    }
  }
  return 0;
}
