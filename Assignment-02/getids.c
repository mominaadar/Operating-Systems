#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
  printf("My Process ID is %d\n", getpid() );
  printf("My Parent's Process ID is %d\n", getppid() );
  exit(0);
}
