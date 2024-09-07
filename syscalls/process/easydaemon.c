#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
  daemon(0,0);
  while(1)
  {
    sleep(10);
    /*do something*/
    printf("Hello World!\n");
  }

  return 0;
}
