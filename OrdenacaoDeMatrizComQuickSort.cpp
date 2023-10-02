#include <stdio.h>

void quickSort(int arr[], int esquerda, int direita) {
    int i = esquerda, j = direita;
    int temp;
    int pivo = arr[(esquerda + direita) / 2];

    while (i <= j) {
        while (arr[i] < pivo)
            i++;
        while (arr[j] > pivo)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (esquerda < j)
        quickSort(arr, esquerda, j);
    if (i < direita)
        quickSort(arr, i, direita);
}

void ordenarMatriz(int matriz[], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        quickSort(matriz + i * colunas, 0, colunas - 1);
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

