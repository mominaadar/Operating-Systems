#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char **argv){

  int pid;
  pid = fork();

  if (pid==-1){
    perror("Error");
  }

  else if (pid==0){
    printf("In Child %d\n", getpid() );
  }

  else{
    wait(NULL);
    printf("Parent's PID:  %d\n", getppid() );
    printf("Child's PID: %d\n", getpid() );
  }

  sleep(1);
  exit(0);

}
