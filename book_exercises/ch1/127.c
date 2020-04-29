#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isprime(const unsigned int challenger)
{
	unsigned int divisor = 2;
	while(divisor<challenger)
	{
		int rest = challenger%divisor;
		if(rest==0)
		{
			return false;
		}
		divisor++;
	}
	return true;
}

int main(void)
{
	unsigned int counter = 0;

	for(int i = 2; i <= 1000; i++)
	{
		if(isprime(i))
		{
			counter++;
			printf("%d is prime\n", i);
		}
	}
	printf("total is %d\n", counter);
	exit(0);
}
