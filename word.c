#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *current,*challenger = 0;
int current_length,challenger_length = 0;

int main(void)
{
	current = (char*) malloc(sizeof(char*));
	challenger = (char*) malloc(sizeof(char*));
	int next = getchar();

	while (next!=EOF)
	{
		//build challenger
		while (isalpha(next))
		{
			challenger[challenger_length++] = (char) next;
			if (challenger_length > current_length)
			{
				challenger = (char*) realloc(challenger, challenger_length * sizeof(char*));
				if (challenger == NULL)
				{
					printf("error when realloc challenger");
					free(current);
					free(challenger);
					exit(0);
				}
			}
			next = getchar();
		}

		//actions if challenger > current
		if (challenger_length > current_length)
		{
			current_length = challenger_length;
			current = (char*) realloc(current, current_length * sizeof(char*));
			if (current == NULL)
			{
				printf("error when realloc current");
				free(current);
				free(challenger);
				exit(0);
			}
			for (int i = 0; i < current_length; i++)
			{
				current[i] = challenger[i];
			}
		}
		challenger_length = 0;
		next = getchar();
	}

	printf("%d characters in longest word: %s\n", current_length, current);
	free(current);
	free(challenger);
	return 0;
}
