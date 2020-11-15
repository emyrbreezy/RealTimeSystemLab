#include <stdio.h>    //a wonderful list of function.
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 

//T1=(4,1.0) T2=(5,1.8) T3=(20,1.0) T4=(20,2.0)


//int myArray[17]={4,1,1.8,0,1,0,2,1.8,1,0,1.8,1,0,1,0,1.8,0} //haven't used this


float time_accumulated;
struct timeval start, end;

float task_1_duration=1.0;
float task_2_duration=1.8;
float task_3_duration=1.0;
float task_4_duration=2.0;
int hyperperiod=20.0;

void task1()		//simple task that runs for 1 sec. 
{

	printf("Task 1:\n\n");
	printf("Process Duration: %.2f\n",task_1_duration);
	sleep(task_1_duration);
	time_accumulated = time_accumulated + task_1_duration;
}

void task2()		//simple task that runs for 1.8 sec
{
	
	printf("Task 2:\n\n");
	printf("Process Duration: %.2f\n",task_2_duration);
	sleep(task_2_duration);
	time_accumulated = time_accumulated + task_2_duration;
	
}

void task3()		//simple task that runs for 1 sec
{
	printf("Task 3:\n\n");
	printf("Process Duration: %.2f\n",task_3_duration);
	sleep(task_3_duration);
	time_accumulated = time_accumulated + task_3_duration;
}


void task4()		//simple task that runs for 2 sec 
{
	printf("Task 4:\n\n");
	printf("Process Duration: %.2f\n",task_4_duration);
	sleep(task_4_duration);
	time_accumulated = time_accumulated + task_4_duration;
}

void delay() //delay for hyperperiod

{	
	int time_unused;

	
	time_unused = hyperperiod - time_accumulated;
	
	printf("Starting Slack Time\n");
	for(int i = 0;i < time_unused;i++)
	{
	        printf("#");
        	fflush(stdout);
		sleep(1);
	}
	
	time_accumulated = 0;
    
	printf("\nSlack Time ended\n\n");	  

}

void timer_start()
{

	gettimeofday(&start, NULL);

}

void timer_end()
{

	double elapsedTime;


	gettimeofday(&end, NULL);
	elapsedTime += (end.tv_usec - start.tv_usec);
	printf("Execution Time: %f Microseconds.\n", elapsedTime);


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

void total_time()
{

printf("Time accumulated :%.2f\n",time_accumulated);

}



void main()

{

//where it all happens

while(1)
{


	if(time_accumulated<=20){
		timer_start();
		task1();
		timer_end();
		haziq_computertime();
		total_time();}
	else{
		delay();
		}	
	
	if(time_accumulated<=20){
		timer_start();
		task2();
		timer_end();
		haziq_computertime();
		total_time();}
	else{
		delay();}
		
	if(time_accumulated<=20){
		timer_start();
		task3();
		timer_end();
		haziq_computertime();
		total_time();}
	else{
		delay();}
		
	if(time_accumulated<=20){
		timer_start();
		task4();
		timer_end();
		haziq_computertime();
		total_time();}
	else{
		delay();}
	
}
}


