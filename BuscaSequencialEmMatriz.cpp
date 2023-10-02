#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int buscarValor(int matriz[][COLUNAS], int valor, int *linha, int *coluna) {
    for (*linha = 0; *linha < LINHAS; (*linha)++) {
        for (*coluna = 0; *coluna < COLUNAS; (*coluna)++) {
            if (matriz[*linha][*coluna] == valor) {
                return 1; // Valor encontrado
            }
        }
    }
    return 0; // Valor não encontrado
}

int main() {
    int matriz[LINHAS][COLUNAS] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    int valorBuscado = 5;
    int linhaEncontrada, colunaEncontrada;

    if (buscarValor(matriz, valorBuscado, &linhaEncontrada, &colunaEncontrada)) {
        printf("Valor %d encontrado na posicao (%d, %d).\n", valorBuscado, linhaEncontrada, colunaEncontrada);
    } else {
        printf("Valor %d nao encontrado na matriz.\n", valorBuscado);
    }

    return 0;
}

