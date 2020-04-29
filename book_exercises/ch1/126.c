#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isperfect(const unsigned int challenger)
{
	unsigned int divisor = 1;
	unsigned int sum = 0;
	while(divisor<challenger)
	{
		int rest = challenger%divisor;
		if(rest==0)
		{
			sum += divisor;
		}
		divisor++;
	}
	if(sum==challenger)
		return true;
	else
		return false;
}

int main(void)
{
	unsigned int counter = 0;
	for(int i = 1; i <= 10000; i++)
	{
		if(isperfect(i))
		{
			counter++;
			printf("%d is perfect\n", i);
		}
	}
	printf("total is %d\n", counter);
	exit(0);
}
