
//-------MOMINA ATIF DAR   P18-0030   SECTION:B

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <sched.h>
#define _GNU_SOURCE


int fn(){ //for clone() example

	printf("Child process\n");
}

void main(int argc, char *argv[]){

	printf("Start...\n");
	
	void *stack = malloc(1024*1024); //in clone() we do memory allocation ourself
	
	int pid = clone(fn, stack + (1024+1024), SIGCHLD, NULL); //clone() creates a child process which is given an external work to do i.e. doesn't execute same code like fork. In fork execution of same code occurs starting from following line but in clone it doesn't happen 
	
	wait(NULL);
	
	free(stack); //to free memory that we allocated before
	
	printf("Memory freed\n");

	//-----------------------------------------------------------------------------------------------------
	printf("-----\n");
	
 	printf("User id: %d\n", getuid()); //this gives id of user
	
	printf("User id2: %d\n", geteuid()); //this is same as getuid(), it gives user id
	
	printf("Group id: %d\n", getgid()); //this gives id of group
	
	printf("Group id2: %d\n", getegid()); //same as getgid(), this gives id of user
	
	//-----------------------------------------------------------------------------------------------------------------------

	printf("-----\n");

	char buffer[500];
	
	int fileh = open("txt4", O_RDONLY);
	
	lseek(fileh, 1, SEEK_SET); //this function sets position of read/write file's offset, '1' means to start seeking from 1st position i.e. start of file
	read(fileh, buffer, 500); //to read data that above mentioned function has sought
	
	printf("File data: %s", buffer);
	
	close(fileh);
	
	//----------------------------------------------------------------------------------------------------------------
	
	printf("-----\n");

	struct stat status;
	
	stat("txt1.txt", &status); //it gives file status of file pointed to by pathname
	printf("st_mode: %d\n", status.st_mode);
	
	
	struct stat status2;
	
	int fd = open("txt1.txt", O_RDONLY);
	fstat(fd, &status2); //it also gives file status but it involves file descriptor
	printf("st_mode2: %d\n", status2.st_mode);
	
	close(fd); 
	
	//-----------------------------------------------------------------------------------------------
	
	printf("-----\n");
	
	if (access("txt1", F_OK) == 0){ //access() checks whether the file exists or not with F_OK mode. If it exists then it returns 0, in case it doesn't exist it returns -1
		printf("File exists\n");
	
	}
	
	int y = access("txt1", X_OK); //X_OK tells checks permissions of file, if permission of any 'r' 'w' or 'x' is granted it will return 0, otherwise 1
	printf("Access permissions: %d\n",y);
	
	//--------------------------------------------------------------------------------------------

	printf("-----\n");
	
	int w = chmod("txt1", strtol("766",NULL,8)); //strtol() converts string to integer, it will change the permissions of file to rw-rw-rw
	printf("chmod: %d\n",w);
	
	//------------------------------------------------------------------------------------------------
	
	printf("-----\n");
	
	uid_t uid;
	gid_t gid;
	struct passwd *pwd;
	struct group *grp;
	
	pwd = getpwnam("momina"); //it gets password file entry
	uid = pwd->pw_uid;
	
	grp = getgrnam("momina"); //get group file entry
	gid = grp->gr_gid;
	
	int v = chown("txt1", uid, gid); //chown changes the owner and group of file
	printf("chown: %d\n",v);
	
	
	//----------------------------------------------------------------------------------------------
	
	printf("-----\n");
	
	int x = fork(); //this will create a child process whose execution will start from this line onwards and 2 Hello World will be printed
	
	printf("Forked\n");
	
	if (x==0){ //to occur only in child process
	
		execv("./addition",NULL); //this will execute addition file but 'Line 3' is not printed because execv doesn't return anything
	}
	
	else{
	
		char buf[50];
	
		printf("CWD before: %s\n",getcwd(buf, sizeof(buf))); //getcwd() gets us current working directory i.e /home/momina/Documents/OS-LAB/assign1
		
		
		int u = chdir("/home/momina/Documents/OS-LAB"); //chdir changes cwd to the directory path specified
		printf("chdir: %d\n",u); //prints 0 if CWD is changed, -1 if not changed
			
		printf("CWD later: %s\n",getcwd(buf, sizeof(buf))); //gets us current working directory i.e /home/momina/Documents/OS-LAB
		
		kill(getpid(),SIGKILL); //this will kill process whose pid is passed i.e. parent process and will display 'Killed'. 'Line 3' will not be executed because parent and child both have ended (child was execv-ed and parent was killed)
	}
	
	printf("End..\n");
	

}
