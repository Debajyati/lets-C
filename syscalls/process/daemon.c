#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <syslog.h>

/*code copied from 
 * https://psychocod3r.wordpress.com/2019/03/19/how-to-write-a-daemon-process-in-c/
 * */

void daemonize( char *cmd ){
  pid_t pid;

  /* Clear file creation mask */
  umask(0);

  /* Spawn a new process and exit */
  if( (pid = fork()) < 0){ /* Fork error */
    fprintf( stderr, "%s: Fork error\n", cmd );
    exit( errno );
  }
  else if( pid > 0){ /* Parent process */
    exit( 0);
  }
  /* Child process */
  setsid();

  /* Change working directory to root directory */
  if( chdir( "/" ) < 0){
    fprintf( stderr, "%s: Error changing directory\n", cmd );
    exit( errno );
  }

  /* Close all open file descriptors */
  for( int i = 0; i < 1024; i++ ){
    close( i );
  }

  /* Reassociate file descriptors 0, 1, and 2with /dev/null */
  int fd0= open( "/dev/null", O_RDWR );
  int fd1= dup( 0);
  int fd2= dup( 0);

  /* Open the log file */
  openlog( cmd, LOG_CONS, LOG_DAEMON );
  if( fd0!= 0|| fd1!= 1|| fd2!= 2){
    syslog( LOG_ERR, "Unexpected file descriptors %d, %d, %d\n",
        fd0, fd1, fd2);
    exit( errno );
  }
}
