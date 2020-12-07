#include <stdio.h>    
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 




void task1(){

	pid_t childpid = fork();
	if(childpid < 0)
	{
 	   printf("Bad day kid, an error");
	}
	else if(childpid == 0)
	{	

  	char *binaryPath = "/home/ubuntu/Desktop/Assignment/task1";
  	char *arg1 = "";
  	char *arg2 = "";
 
  execl(binaryPath, binaryPath, arg1, arg2, NULL);

	}	
	else
	{
		printf("Next task");
	}
  
}

void task2(){

	pid_t childpid = fork();
	if(childpid < 0)
	{
 	   printf("Bad day kid, an error");
	}
	else if(childpid == 0)
	{	

  	char *binaryPath = "/home/ubuntu/Desktop/Assignment/task2";
  	char *arg1 = "";
  	char *arg2 = "";
 
  execl(binaryPath, binaryPath, arg1, arg2, NULL);

	}	
	else
	{
		printf("Next task");
	}
  ;
  
}

void task3(){

  char *binaryPath = "/home/ubuntu/Desktop/Assignment/task3";
  char *arg1 = "";
  char *arg2 = "/home";
 
  execl(binaryPath, binaryPath, arg1, arg2, NULL);
  
}

void task4(){

  char *binaryPath = "/home/ubuntu/Desktop/Assignment/task4";
  char *arg1 = "-lh";
  char *arg2 = "/home";
 
  execl(binaryPath, binaryPath, arg1, arg2, NULL);
  
}


void main(){

	task1();
	task2();
	task3();
	task4();

}

