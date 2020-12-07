#define _POSIX_C_SOURCE 200809L

#include <inttypes.h>
#include <signal.h>
#include <stdio.h>    
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

timer_t gTimerid;

void delay(int number_of_seconds) 
{ 

int milli_seconds = 1 * number_of_seconds; 
clock_t start_time = clock(); 
while (clock() < start_time + milli_seconds) ; 
} 

void start_timer()
{


struct itimerspec value;

value.it_value.tv_sec= 1;      //initial expiration  
value.it_value.tv_nsec= 800000000;  //.8 s
value.it_interval.tv_sec= 1;	//period
value.it_interval.tv_nsec= 0;  //1 ns
timer_create(CLOCK_MONOTONIC, NULL, &gTimerid);
timer_settime(gTimerid, 0, &value, NULL);

}

void mySigAlarmHandler(int sig) {


struct timespec begin, end;
float elapsed_time;
float elapsed_time_ns;


clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

printf("\nTask 2: Subtraction\n");

int x = 1;
int y = 2;
int z;

z = y-x;

printf("\n2 - 1 is %d \n",z);

printf("\nEnd of Task 2\n");

delay(1800);
clock_gettime(CLOCK_MONOTONIC_RAW, &end);

elapsed_time = ((end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec));
elapsed_time_ns = elapsed_time * 1000000000;

printf ("Total time = %.0f nanoseconds\n", elapsed_time_ns);
printf("-------------------------\n");

printf("Catchedtimer signal: %d ... !! %d\n", sig, getpid());
(void) signal(SIGINT, mySigAlarmHandler);

}

int main(int ac, char **av)
{
(void) signal(SIGALRM, mySigAlarmHandler);
start_timer();
while(1);
}
