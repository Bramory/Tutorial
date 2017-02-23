#include "prime.h"
#include <stdio.h>

void sieve ( int size, char numbers[size] )
{
	int i, j;
	for (i = 2; i * i <= size; i++)
		if ( numbers[i] != 0)
			for(j = i+i; j < size; j += i )
				numbers[j] = 0;
}


int prime_list(int size, char numbers[size] )
{
	int i, counter = 0;
		for(i = 2; i < size; i ++ )
		{
			if ( numbers[i] != 0) 
			{
			printf ("%i ", i );
			counter++;
			}
		}
	return counter;
}

int prime_file(int size, char numbers[size])
{
	int i, counter = 0;
	FILE *file = fopen("Prime.txt", "w");
	if (NULL != file)
	{
		for(i = 2; i < size; i ++ )
		{
			if ( numbers[i] != 0) 
			{
			fprintf (file, "%i ", i );
			counter++;
			}
		}
	close(file);
	return counter;
	}
	else printf("Smth went wrong..");
	return -1;
}
