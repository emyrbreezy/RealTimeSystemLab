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

printf("\nTask 2: Subtraction\n");

int x = 1;
int y = 2;
int z;

z = y-x;

printf("\n2 - 1 is %d \n", z);



printf("\nEnd of Task 2\n");

sleep(1.8);

timer_end();
printf("-------------------------\n");

}
