#include <stdio.h>
#include <limits.h>




int main(void)
{
	unsigned int counter = 0;

	unsigned short s = USHRT_MAX;
	unsigned int i = UINT_MAX;
	unsigned long l = ULONG_MAX;
	unsigned long long ll = ULLONG_MAX;
	while (s > 0)
	{
		s = s << 1;
		counter++;
	}

	printf("USHRT_MAX has %d bits and is %d\n", counter, USHRT_MAX);

	counter = 0;

	while (i > 0)
	{
		i = i << 1;
		counter++;
	}

	printf("UINT_MAX has %d bits and is %u\n", counter, UINT_MAX);

	counter = 0;

	while (l > 0)
	{
		l = l << 1;
		counter++;
	}

	printf("ULONG_MAX has %d bits and is %lu\n", counter, ULONG_MAX);

	counter = 0;

	while (ll > 0)
	{
		ll = ll << 1;
		counter++;
	}

	printf("ULLONG_MAX has %d bits and is %llu\n", counter, ULLONG_MAX);

	counter = 0;
	return 0;
}
