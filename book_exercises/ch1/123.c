#include <time.h>
#include <stdio.h>

int main(void)
{
	clock_t begin = clock();

	long double x = 1;
	long double sum = 0;
	while (sum < 18)
	{
		sum += 1/(x++);
	}

	clock_t end = clock();
	double t = (end - begin) / (double)CLOCKS_PER_SEC;
	printf("work: %1.3lf s\non iteration %Lf\nthe sum is %Lf\n", t, x, sum);

	return 0;
}
