#include <stdio.h>
#include <stdlib.h> //system
#include <sys/types.h> //fork and wait
#include <unistd.h> //fork
#include <sys/wait.h> //wait

int main (){

	printf("Hello World\n");
	printf("Process ID: %d\n", getpid());
	printf("Parent process id: %d\n", getppid() );

	int x = fork(); // f1

	if (x == 0){
		printf("Process ID: %d\n", getpid());
		printf("Parent process id: %d\n\n", getppid() );
	}

	else if (x > 0){
		printf("Process ID: %d\n", getpid());
		printf("Parent process id: %d\n\n", getppid() );
	}

	return 0;

}
