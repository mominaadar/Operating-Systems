#include <stdio.h>
#include <stdlib.h> //system
#include <sys/types.h> //fork and wait
#include <unistd.h> //fork
#include <sys/wait.h> //wait

int main (){

	int a,b,c,d,e,f,g,h,i;
	printf("P1\n");
	a = fork();
	
	if (a>0){
		printf("P2 created\n");
		b = fork();
	
		if (a>0 && b>0){
			printf("P3 created\n");
			c = fork();
		}
	}
	
	if (a>0 && b==0){
		printf("P4 created\n");
		d = fork();
			
	
		if (a>0 && b==0 && d>0){
			printf("P5 created\n");
			e = fork();
		}
	}
	
			
					
	if (a>0 && b>0 && c==0){
		printf("P6 created\n");
		f = fork();
	
		if (a>0 && b>0 && c==0 && f>0){
			printf("P7 created\n");
			g = fork();
		
		}
	}
	
	if (a==0){
		printf("P8 created\n");
		h = fork();

	}

	
	
	if (a>0 && b>0 && c==0 && f>0 && g>0){
		printf("P9 created\n");
		i = fork();
		
		if(a>0 && b>0 &&c==0 && f>0 && g>0 && i==0){
			printf("P10 created\n");
		}
	}


	return 0;
}

// It's easily performed with if-else statement as in we just have to keep track of the values we are getting back. We draw up a tree and on every fork call just follow the if statement's condition and do fork. It's easier to keep track this way.
