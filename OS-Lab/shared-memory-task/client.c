#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> //shmat
#include <unistd.h>
#include <sys/ipc.h> //shmget
#include <sys/shm.h> //shmget, shmat
#include <string.h> //memcpy

#define sizeofdata 500

void main(){

	char string[5000];	

	FILE * fname;
	FILE * fname2;
	

	fname2 = fopen("message_history","r");
	
	fscanf(fname2,"%[^\n]",string); //[^\n] scans the whole line
	
	
	fname = fopen("message_history","w");


	key_t key = 7896;

	int shmid = shmget(key, sizeofdata, 0777 | IPC_EXCL);

	char *shm = shmat(shmid, NULL, 0);


	strcat(string,shm); //concatenation 

	fprintf(fname,"%s",string); //writing to file


	shmdt(shm);	
	shmctl(shmid, IPC_RMID, NULL);


	fclose(fname);
	fclose(fname2);

}
