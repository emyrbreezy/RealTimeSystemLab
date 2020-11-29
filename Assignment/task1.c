#include <stdio.h>    
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> 

struct timeval start, end;

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


void main(){


timer_start();
printf("\nTask 1: Addition\n");

int x = 1;
int y = 2;
int z;

z = x+y;

printf("\n1 + 2 is %d \n",z);



printf("\nEnd of Task 1\n");

sleep(1);
timer_end();
printf("-------------------------\n");

}
