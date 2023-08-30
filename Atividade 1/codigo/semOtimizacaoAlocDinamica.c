#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 800

// a X b = c

void printMatriz(int m[][SIZE]);
void deletarMatriz(int **matriz);
int** criarMatriz();

int main(int argc, char** const argv)
{
    srand(time(NULL));

    int** a = criarMatriz();
    int** b = criarMatriz();
    int** c = criarMatriz();

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            for(int k = 0; k < SIZE; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    deletarMatriz(a);
    deletarMatriz(b);
    deletarMatriz(c);

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

int** criarMatriz()
{
    int** m = (int**)malloc(SIZE * sizeof(int*));
    for(int i = 0; i < SIZE; i++)
    {
        m[i] = (int*)malloc(SIZE * sizeof(int));

        for(int j = 0; j < SIZE; j++)
        {
            m[i][j] = rand() % 10;
        }
    }

    return m;
}

void deletarMatriz(int **matriz) {
    for (int i = 0; i < SIZE; i++) {
        free(matriz[i]);
    }
    free(matriz);
}