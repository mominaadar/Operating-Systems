#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MSGSZ 128 

struct msg_buff{

	long mtype;
	char mtext[1];

};

void main(){ 
	
	struct msg_buff r_buff;
	
	key_t key = 12345;
	
	double f = -INFINITY;
	int count = 0;
	
	int msgid = msgget(key, 0666);
	
	while(f==f){

		msgrcv(msgid, &r_buff, MSGSZ, 3, 0);
		
		printf("%s", r_buff.mtext);
		
		count = count + 1;

		
		if (count==10){
			printf("\n");
		}

		if (count==20){
			printf("\n");
		}	
			
	}
}
