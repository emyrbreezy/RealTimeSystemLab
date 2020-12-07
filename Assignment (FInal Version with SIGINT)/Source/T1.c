#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>

int main()
{
char *args[]={NULL,NULL};
int k;
int pid;
int ttk[]={1,3,2,0,1,0,4,2,1,0,2,1,0,1,0,2,0};
float tk[]={0,1,2,3.8,4,5,6,8,9.8,10.8,12,13.8,14.8,16,17,17,19.8};

	while(1)
	{
	//pid=fork();
	for(k=0;k<17;k++){
		pid=fork();
		if(pid>0)
		   {
			wait(NULL);
			
		    }
			
			else if(pid==0)
		   		{
					//execl("./task1_1","","",(char *)0);
					printf("This is child\n");
					//exit(0);

						switch(ttk[k]){
							case 1:
					   			args[0]="./task1";
					   			break;
							case 2:
					  			 args[0]="./task2";
					   			break;
							case 3:
					   			args[0]="./task3";
					   			break;
							case 4:
					   			args[0]="./task4";
					   			break;
							default:
					  			printf("\nTask %d not defined..\n",ttk[k]);
		    					}
		execvp(args[0],args);
		}
	
		else
			{
			printf("Error:fork fails to create process\n");
			}
		}
	}
return 0;
}
