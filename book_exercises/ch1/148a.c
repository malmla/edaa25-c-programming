#include <stdio.h>
#include <stdlib.h>

void input(double *a, size_t size)
{
	int e;
	double in = 0;
	for(int i = 0; i < size; i++)
	{
		printf("Input next element: \n");
		e = scanf("%lf", &in);
		*(a+i) = in;
		if (e != 1)
			printf("input went wrong\n");
	}
}

void output(double *a, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		printf("element %u is %lf\n", i, *(a+i));
	}
}

/*
 * Reads size doubles from input and puts them in an array. Using pointers instead of brackets.
 */

int main(void)
{
	size_t size = 0;
	printf("How many inputs are you putting in?\n");
	int arguments = scanf("%zu", &size);
	if (arguments != 1)
		printf("input went wrong\n");
	double* a = (double*) malloc(size * sizeof(double*));
	input(a, size);
	output(a, size);
	free(a);
}
