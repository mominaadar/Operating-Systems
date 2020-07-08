#include <stdio.h>
#include <stdlib.h> //system
#include <sys/types.h> //fork and wait
#include <unistd.h> //fork
#include <sys/wait.h> //wait

void main (){

	int x = fork();

	printf("Hello World\n");
	
	int y = fork();
 
	if (x == 0 || y > 0){
		printf("OS LAB\n");
	}
}
