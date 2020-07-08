#include <stdio.h>
#include <sys/types.h> //fork and wait
#include <unistd.h> //fork

void main (){
	int a,b,c,d;
	a=fork();
	b=fork();
	c=fork();


	if (a==0 || b>0 && c>0){
		printf("hello world\n");
		
	}

		d=fork();


	if ((a>0 && b>0) || d>0 || (a==0 && b==0 && c==0)){
		printf("OS LAB\n");
	}
	
}
