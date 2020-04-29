#include <stdlib.h>
#include <stdio.h>

void swap(int *vara, int *varb)
{
	int temp = *vara;
	*vara = *varb;
	*varb = temp;
}

void order(int* in1, int* in2)
{
	if(*in1 > *in2)
	{
		swap(in1, in2);
	}
}

int main(void)
{
	int a, b;
	printf("Enter var a: ");
	int error = scanf("%d", &a);
	printf("Enter var b: ");
	error = scanf("%d", &b);

	error++;
	order(&a,&b);

	printf("a = %d, b = %d\n", a, b);
}
