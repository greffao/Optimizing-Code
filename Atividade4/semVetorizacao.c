#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 1000 // 10 mil
#define N_MAX 1000 // 1 mil


long long int produtoInterno(long long int *a, long long int *b)
{
    long long int result = 0.0;

    for (int i = 0; i < TAM_VETOR; i++)
    {
        result += a[i] * b[i];
    }
    return result;
}

int main()
{
    srand(time(NULL));

    const int N_VEZES = 100000; // 100 mil

    for(int k = 0; k < N_VEZES; k++)
    {
        long long int a[TAM_VETOR];
        long long int b[TAM_VETOR];


        for(int i = 0; i < TAM_VETOR; i++)
        {
            a[i] = rand() % N_MAX;
            b[i] = rand() % N_MAX;
        }

        produtoInterno(a, b);

        //printf("%lli\n", produtoInterno(a, b));
    }


    return 0;
}
