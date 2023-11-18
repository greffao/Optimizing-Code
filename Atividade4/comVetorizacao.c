#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

#define TAM_VETOR 1000 // 10 mil
#define N_MAX 100 // 100
#define ALIGN 32

long long int produtoInterno(long long int *a, long long int *b) {
    __m256i result = _mm256_setzero_si256();

    for (int i = 0; i < TAM_VETOR; i += 4) {
        __m256i a_vec = _mm256_loadu_si256((__m256i*)&a[i]);
        __m256i b_vec = _mm256_loadu_si256((__m256i*)&b[i]);
        result = _mm256_add_epi64(result, _mm256_mul_epi32(a_vec, b_vec));
    }

    long long int final_result[4] __attribute__((aligned(ALIGN)));
    _mm256_store_si256((__m256i*)final_result, result);

    long long int final_sum = 0;
    for (int i = 0; i < 4; ++i) {
        final_sum += final_result[i];
    }

    return final_sum;
}

int main() {
    srand(time(NULL));

    const int N_VEZES = 100000; // 100 mil

    for (int k = 0; k < N_VEZES; k++) {
        long long int a[TAM_VETOR] __attribute__((aligned(ALIGN)));
        long long int b[TAM_VETOR] __attribute__((aligned(ALIGN)));

        for (int i = 0; i < TAM_VETOR; i++) {
            a[i] = rand() % N_MAX;
            b[i] = rand() % N_MAX;
        }

        produtoInterno(a, b);
    }

    return 0;
}
