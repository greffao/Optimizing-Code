#include <iostream>
#include <immintrin.h>

void somaMatrizes(int *matrizA, int *matrizB, int *resultado, int tamanho) {
    for (int i = 0; i < tamanho * tamanho; i += 4) {
        __m128i a = _mm_loadu_si128((__m128i *)&matrizA[i]);
        __m128i b = _mm_loadu_si128((__m128i *)&matrizB[i]);
        __m128i sum = _mm_add_epi32(a, b);
        _mm_storeu_si128((__m128i *)&resultado[i], sum);
    }
}

void multiplicaMatrizes(int *matrizA, int *matrizB, int *resultado, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; j += 4) {
            __m128i partialSum = _mm_setzero_si128();
            for (int k = 0; k < tamanho; ++k) {
                __m128i a = _mm_set1_epi32(matrizA[i * tamanho + k]);
                __m128i b = _mm_loadu_si128((__m128i *)&matrizB[k * tamanho + j]);
                partialSum = _mm_add_epi32(partialSum, _mm_mullo_epi32(a, b));
            }
            _mm_storeu_si128((__m128i *)&resultado[i * tamanho + j], partialSum);
        }
    }
}

void exibirMatriz(int *matriz, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            std::cout << matriz[i * tamanho + j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int tamanho = 24;
    int matrizA[tamanho * tamanho];
    int matrizB[tamanho * tamanho];

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            matrizA[i * tamanho + j] = rand() % 100 + 1;
            matrizB[i * tamanho + j] = rand() % 100 + 1;
        }
    }

    int resultadoSoma[tamanho * tamanho];
    int resultadoMultiplicacao[tamanho * tamanho];

    multiplicaMatrizes(matrizA, matrizB, resultadoMultiplicacao, tamanho);

    somaMatrizes(resultadoMultiplicacao, matrizB, resultadoSoma, tamanho);

    somaMatrizes(resultadoMultiplicacao, matrizA, resultadoSoma, tamanho);


    return 0;
}
