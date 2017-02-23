#include <stdio.h>
#include <math.h>
#include "prime.h"
int const N = pow(10, 3);

int main() 
{
	unsigned char *numbers = malloc(sizeof(char) * N);
	int i, j, counter = 0;
	
	memset (numbers, 0, sizeof(numbers));
	for(i = 2; i < N; i++ )
	{
		numbers[i] = 1;
	}
	
sieve(N, numbers );
//counter = prime_list (N, numbers);
counter = prime_file(N, numbers);
printf ("\n Primes -  %i", counter);

printf ("\n Memory usage -  %.3f Mb", (float) sizeof(char)*N  * pow(10, -6) );	
free(numbers);
return 0;
}
