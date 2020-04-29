#include <stdio.h>

unsigned int hexadecimal_digit_sum(unsigned int value)
{
	unsigned int sum = 0x0;
	while (value > 0)
	{
		sum += value % 0x10;
		value >>= 4;
	}
	return sum;
}

int main(void)
{
	unsigned int in;
	int i = 0;
	while (i != EOF || i == 0)
	{
		printf("enter hexadecimal number: ");
		i = scanf("%x", &in);
		unsigned int sum = hexadecimal_digit_sum(in);
		printf("input %x gives sum %u\n", in, sum);
	}

}

