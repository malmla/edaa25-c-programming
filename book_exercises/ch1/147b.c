#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE (12)

/*
 * Calculate sum of doubles, in this case only positive doubles, using pointers
 */

int main(void)
{
	int next = getchar();
	double* array = (double*) calloc(SIZE, sizeof(double*));
	unsigned int index = 0;
	unsigned int decimals;
	while(next != EOF)
	{
		while(isdigit(next))
		{
			*(array+index) = *(array+index) * 10 + (next - '0');
			next = getchar();
		}
		if(next == '.')
		{
			decimals = 0;
			next = getchar();
			while(isdigit(next))
			{
				*(array+index) = *(array+index) * 10 + (next - '0');
				decimals++;
				next = getchar();
			}
			*(array+index)/=pow((double)10,(double)decimals);
		}
		next = getchar();
		index++;
	}

	for(int i = 1; i < index && index > 1; i++)
	{
		*array += *(array+i);
	}
	printf("sum = %lf\n", *array);
	free(array);
}
