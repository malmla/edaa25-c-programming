#include <stdlib.h>
#include <stdio.h>

void swap(int *vara, int *varb)
{
	int temp = *vara;
	*vara = *varb;
	*varb = temp;
}

int main(void)
{
	int a, b;
	printf("Enter var a: ");
	int error = scanf("%d", &a);
	printf("Enter var b: ");
	error = scanf("%d", &b);

	error++;
	swap(&a,&b);

	printf("a = %d, b = %d\n", a, b);
}
