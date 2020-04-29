#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool leap_year(unsigned short int year)
{
	return !(year%=4);
}

int main(void)
{
	int next = getchar();
	unsigned int input_year = 0;

	while(next != EOF)
	{
		while(isdigit(next))
		{
		input_year = 10 * input_year + (next - '0');
		next = getchar();
		}

		printf("the year %d is ", input_year);
		if(leap_year(input_year))
		{}
		else
		{
			printf("not ");
		}
		printf("a leap year\n");
		input_year = 0;
		next = getchar();
	}

	exit(0);
}
