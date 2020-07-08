/* credit of this file goes to Momina Atif dar (during the submission of assignment # 03) */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msg_buff{

	long mtype;
	char mtext[1];
	

};

void main(int argc, char *argv){ 

	int str[20];
	char str2[20];


	struct msg_buff s_buff;
	
	key_t key = 12345;
	
	int msgid = msgget(key, 0666 | IPC_CREAT);
	
	
	s_buff.mtype = 1;
	strcpy(s_buff.mtext, "U");
	size_t buff_len1 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len1, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "D");
	size_t buff_len2 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len2, IPC_NOWAIT);
	
	s_buff.mtype = 2;
	strcpy(s_buff.mtext, "F");
	size_t buff_len3 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len3, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "I");
	size_t buff_len4 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len4, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "S");
	size_t buff_len5 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len5, IPC_NOWAIT);
	
	s_buff.mtype = 1;
	strcpy(s_buff.mtext, "N");
	size_t buff_len6 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len6, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "C");
	size_t buff_len7 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len7, IPC_NOWAIT);
	
	s_buff.mtype = 2;
	strcpy(s_buff.mtext, "A");
	size_t buff_len8 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len8, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "I");
	size_t buff_len9 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len9, IPC_NOWAIT);
	
	s_buff.mtype = 1;
	strcpy(s_buff.mtext, "I");
	size_t buff_len10 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len10, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "P");
	size_t buff_len11 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len11, IPC_NOWAIT);
	
	s_buff.mtype = 2;
	strcpy(s_buff.mtext, "I");
	size_t buff_len12 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len12, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "L");
	size_t buff_len13 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len13, IPC_NOWAIT);
	
	s_buff.mtype = 1;
	strcpy(s_buff.mtext, "T");
	size_t buff_len14 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len14, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "I");
	size_t buff_len15 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len15, IPC_NOWAIT);
	
	s_buff.mtype = 2;
	strcpy(s_buff.mtext, "T");
	size_t buff_len16 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len16, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "N");
	size_t buff_len17 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len17, IPC_NOWAIT);
	
	s_buff.mtype = 1;
	strcpy(s_buff.mtext, "Y");
	size_t buff_len18 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len18, IPC_NOWAIT);
	
	s_buff.mtype = 3;
	strcpy(s_buff.mtext, "E");
	size_t buff_len19 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len19, IPC_NOWAIT);
	
	s_buff.mtype = 2;
	strcpy(s_buff.mtext, "H");
	size_t buff_len20 = strlen(s_buff.mtext)+1;
	msgsnd(msgid, &s_buff, buff_len20, IPC_NOWAIT);
	
}
