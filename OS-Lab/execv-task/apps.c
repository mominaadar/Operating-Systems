#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	printf("loading apps...\n");

	int firefox_fork = fork();

	if (firefox_fork == 0){
		execv("./firefox",NULL);
	}

	int geditor_fork = fork();

	if (geditor_fork == 0){
		execv("./geditor",NULL);
	}

	int terminal_fork = fork();

	if (terminal_fork == 0){
		execv("./terminal",NULL);
	}
	else if (terminal_fork > 0){  //so that these three processes execute completely and simultaneously
		wait(NULL);	
	}


}
