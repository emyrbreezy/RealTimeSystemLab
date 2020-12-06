#include <stdio.h>    
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 

struct timespec begin, end;
float elapsed_time;
float elapsed_time_ns;

void timer_start()
{


    
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

}

void timer_end()
{


	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	
	elapsed_time = ((end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec));
	elapsed_time_ns = elapsed_time * 1000000000;

    printf ("Total time = %.0f nanoseconds\n", elapsed_time_ns);



}


void main(){

timer_start();

printf("\nTask 3: Multiplication\n");

int x = 1;
int y = 2;
int z;

z = x*y;

printf("\n1 x 2 is %d \n", z);



printf("\nEnd of Task 3\n");

sleep(1);

timer_end();
printf("-------------------------\n");


}
