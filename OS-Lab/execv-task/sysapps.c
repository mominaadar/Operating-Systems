#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	printf("loading system apps..\n");

	int antivirus_fork = fork();

	if (antivirus_fork == 0){
		execv("./antivirus",NULL);
	}
	else if(antivirus_fork > 0){
		wait(NULL);
	}


	int backg_fork = fork();

	if (backg_fork == 0){
		execv("./background",NULL);
	}
	else if(backg_fork > 0){
		wait(NULL);
	}

	int ssaver_fork = fork();

	if (ssaver_fork == 0){
		execv("./screensaver",NULL);
	}
	else if(ssaver_fork > 0){
		wait(NULL);
	}

	int dtheme_fork = fork();

	if (dtheme_fork == 0){
		execv("./dtheme",NULL);
	}
	else if(dtheme_fork > 0){
		wait(NULL);
	}

}
