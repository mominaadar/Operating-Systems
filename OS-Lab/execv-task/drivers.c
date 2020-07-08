#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	printf("uploading drivers...\n");

	int gui_fork = fork();

	if (gui_fork == 0){
		execv("./gui",NULL);
	}

	int keyboard_fork = fork();

	if (keyboard_fork == 0){
		execv("./keyboard",NULL);
	}

	int mouse_fork = fork();

	if (mouse_fork == 0){
		execv("./mouse",NULL);
	}

	int usb_fork = fork();

	if (usb_fork == 0){
		execv("./usb",NULL);
	}

	int sdcard_fork = fork();

	if (sdcard_fork == 0){
		execv("./sdcard",NULL);
	}
	else if (sdcard_fork > 0){
		wait(NULL);
	}

}
