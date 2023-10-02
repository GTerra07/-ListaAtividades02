#include <stdio.h>

void insertionSort(int arr[], int n) {
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void ordenarMatriz(int matriz[], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        insertionSort(matriz + i * colunas, colunas);
    }
}

void imprimirMatriz(int matriz[], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i * colunas + j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    int linhas = sizeof(matriz) / sizeof(matriz[0]);
    int colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);

    printf("Matriz antes da ordenacao:\n");
    imprimirMatriz(matriz[0], linhas, colunas);

    ordenarMatriz(matriz[0], linhas, colunas);

    printf("\nMatriz depois da ordenacao:\n");
    imprimirMatriz(matriz[0], linhas, colunas);

    return 0;
}

