#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	printf("init process has been loaded...\n");

	int drivers_fork = fork();

	if (drivers_fork == 0){
		execv("./drivers", NULL);
	}
	else if (drivers_fork > 0){   //if you want drivers portion to completely execute first
		wait(NULL);	
	}

	int apps_fork = fork();

	if (apps_fork == 0){
		execv("./apps", NULL);
	}
	else if (apps_fork > 0){
		wait(NULL);	
	}

	int sysapps_fork = fork();
	
	if (sysapps_fork == 0){
		execv("./sysapps",NULL);
	}	
	else if (sysapps_fork > 0){
		wait(NULL);
	}

}
