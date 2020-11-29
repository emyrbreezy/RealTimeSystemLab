#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_sec)
{
	clock_t start_time = clock();
	while(clock() < start_time + number_of_sec);
}

int main()
{
	while(1)
	{
		printf("T1 is executed\n");
		delay(1.0);
		sleep(19.0);
	}

	return 0;
}

