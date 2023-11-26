#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<vector<int>> somaMatrizes(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int tamanho = matrizA.size();
    vector<vector<int>> resultado(tamanho, vector<int>(tamanho, 0));

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return resultado;
}

vector<vector<int>> multiplicaMatrizes(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int tamanho = matrizA.size();
    vector<vector<int>> resultado(tamanho, vector<int>(tamanho, 0));

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            for (int k = 0; k < tamanho; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return resultado;
}

void inicializarMatrizAleatoria(vector<vector<int>>& matriz, int tamanho) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000); // Intervalo de 1 a 1000

    matriz.resize(tamanho, vector<int>(tamanho, 0));

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            matriz[i][j] = dis(gen);
        }
    }
}


int main() {
    int tamanho = 24;

    vector<vector<int>> matrizA;
    vector<vector<int>> matrizB;

    inicializarMatrizAleatoria(matrizA, tamanho);
    inicializarMatrizAleatoria(matrizB, tamanho);

    vector<vector<int>> multiplicacao = multiplicaMatrizes(matrizA, matrizB);

    vector<vector<int>> soma = somaMatrizes(multiplicacao, matrizA);
    
    soma = somaMatrizes(soma, matrizB);


    return 0;
}
