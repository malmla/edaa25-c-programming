
#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main(void)
{
	double* x = malloc(4 * sizeof(*x));
	x[0] = 0;
	x[1] = 0.1;
	x[2] = 0.2;
	x[3] = 0.3;
	for (int i = 0; i < 4; i++)
	{
		printf("Input %lf gives square root = %lf and power of e = %lf\n", x[i], sqrt(x[i]), exp(x[i]));
	}
	return 0;
}
