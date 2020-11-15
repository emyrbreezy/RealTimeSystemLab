#include <stdio.h>    //a wonderful list of function.
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 

//T1=(4,1.0) T2=(5,1.8) T3=(20,1.0) T4=(20,2.0)


//int myArray[17]={4,1,1.8,0,1,0,2,1.8,1,0,1.8,1,0,1,0,1.8,0} 

int t;
struct timeval start, end;


void task1()		//simple task that runs for 1 sec. 
{
	printf("Task 1:\n\n");
	sleep(1);
}

void task2()		//simple task that runs for 1.8 sec
{
	printf("Task 2:\n\n");
	sleep(1.8);
	
}

void task3()		//simple task that runs for 1 sec
{
	printf("Task 3:\n\n");
	sleep(1);
}


void task4()		//simple task that runs for 2 sec 
{
	printf("Task 4:\n\n");
	sleep(2);

}

void delay() //delay for hyperperiod

{	printf("Hyper period started\n");
	for(int i = 0;i < 20;i++)
	{
	        printf("#");
        	fflush(stdout);
		sleep(1);
	}
    
	printf("\nHyperperiod ended in: 20 seconds\n\n");	  

}

void timer_start()
{

	gettimeofday(&start, NULL);	//start timer based on system time

}

void timer_end()
{

	double elapsedTime;	//time elapsed variable


	gettimeofday(&end, NULL);		//end timer
	elapsedTime += (end.tv_usec - start.tv_usec);		//calculate timer time elapsed
	printf("Execution Time: %f Microseconds.\n", elapsedTime);	//show elapsed time in micro seconds


}


void haziq_computertime()
{

	struct timeval tv;
	// struct timeval tv; //tv argument is a struct timeval
	time_t t;		//data type to store system time value
	struct tm *info;	//Structure containing a calendar date and time
	char buffer[64];	//how much character u want to use
 
	gettimeofday(&tv, NULL); //gets the system's clock time
	t = tv.tv_sec;		//This is the rest of the elapsed time placed in t

	info = localtime(&t);	//converts local time pointed by timer
  
  
	printf("System microseconds clock time: %ld \n\n",tv.tv_usec);
	printf("%s\n",asctime (info)); //print result


}


void main()

{


	while(1){		//loop forever

	timer_start();
	task1();
	timer_end();
	haziq_computertime();

 
	timer_start();   
	task2();
	timer_end();
	haziq_computertime();


	timer_start();
	task3();
	timer_end();
	haziq_computertime();


	timer_start();
	task4();
	timer_end();
	haziq_computertime();

	delay();

}

  

}



