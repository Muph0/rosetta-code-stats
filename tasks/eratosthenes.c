/**
 * from https://rosettacode.org/wiki/Sieve_of_Eratosthenes
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *
eratosthenes(int n, int *c)
{
    char *sieve;
    int i, j;

    if (n < 2)
        return NULL;

    *c = n - 1; /* primes count */

    /* calloc initializes to zero */
    sieve = calloc(n + 1, sizeof(char));
    sieve[0] = 1;
    sieve[1] = 1;
    for (i = 2; i*i <= n; i++)
        if (!sieve[i])
            for (j = i * i; j <= n; j += i)
                if (!sieve[j])
                {
                    sieve[j] = 1;
                    --(*c);
                }
    return sieve;
}

int task_main()
{
    int N = 100000;
    int count;
    char *sieve = eratosthenes(N, &count);

    for (int i = 0; i < N; i++)
    {
    }

    free(sieve);
    return 0;
}
