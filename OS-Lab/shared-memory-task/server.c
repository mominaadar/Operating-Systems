#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> //shmat
#include <unistd.h>
#include <sys/ipc.h> //shmget
#include <sys/shm.h> //shmget, shmat
#include <string.h> //memcpy


void main(int argc, char *argv[]){
	
	char val[5] = "txt";
	char data[500];

	FILE * filehandler;

	strcat(val,argv[1]);

	filehandler = fopen(val,"r");


	if (filehandler == NULL){
		printf("Error in opening file\n");
	}


	key_t key = 7896;

	int shmid = shmget(key, sizeof(data), 0777 | IPC_CREAT);

	char *shm = shmat(shmid, NULL, 0);


	while (fgets(data, sizeof(data), filehandler) != NULL){

		memcpy(shm, data, sizeof(data));

	}


	fclose(filehandler);

}
