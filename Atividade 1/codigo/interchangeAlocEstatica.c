#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 800

// a X b = c

void printMatriz(int m[][SIZE]);

int main(int argc, char** const argv)
{
    int a[SIZE][SIZE];
    int b[SIZE][SIZE];
    int c[SIZE][SIZE];

    srand(time(NULL));

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            a[i][j] = rand() % 3;
            b[i][j] = rand() % 3;
            c[i][j] = 0;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int k = 0; k < SIZE; k++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return 0;
}

void printMatriz(int m[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
}