#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int trocou;

    do {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocou = 1;
            }
        }
    } while (trocou);
}

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

void merge(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        merge(arr, esquerda, meio, direita);
    }
}

int main() {
    int tamanho1 = 1000;
    int tamanho2 = 10000;
    int tamanho3 = 100000;
    int tamanho4 = 1000000;
    
    int *arr1 = (int *)malloc(tamanho1 * sizeof(int));
    int *arr2 = (int *)malloc(tamanho2 * sizeof(int));
    int *arr3 = (int *)malloc(tamanho3 * sizeof(int));
    int *arr4 = (int *)malloc(tamanho4 * sizeof(int));

    clock_t inicio, fim;
    double tempo;

    // Preencha os arrays aleatoriamente ou com seus próprios dados

    // Teste para o Bubble Sort
    printf("Ordenacao por Bolha:\n");

    inicio = clock();
    bubbleSort(arr1, tamanho1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 1: %lf segundos\n", tempo);

    inicio = clock();
    bubbleSort(arr2, tamanho2);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 2: %lf segundos\n", tempo);

    inicio = clock();
    bubbleSort(arr3, tamanho3);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 3: %lf segundos\n", tempo);

    inicio = clock();
    bubbleSort(arr4, tamanho4);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 4: %lf segundos\n", tempo);

    // Teste para o Quick Sort
    printf("Ordenacao por Quick Sort:\n");

    inicio = clock();
    quickSort(arr1, 0, tamanho1 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 1: %lf segundos\n", tempo);

    inicio = clock();
    quickSort(arr2, 0, tamanho2 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 2: %lf segundos\n", tempo);

    inicio = clock();
    quickSort(arr3, 0, tamanho3 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 3: %lf segundos\n", tempo);

    inicio = clock();
    quickSort(arr4, 0, tamanho4 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 4: %lf segundos\n", tempo);

    // Teste para o Merge Sort
    printf("Ordenacao por Merge Sort:\n");

    inicio = clock();
    mergeSort(arr1, 0, tamanho1 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 1: %lf segundos\n", tempo);

    inicio = clock();
    mergeSort(arr2, 0, tamanho2 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 2: %lf segundos\n", tempo);

    inicio = clock();
    mergeSort(arr3, 0, tamanho3 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 3: %lf segundos\n", tempo);

    inicio = clock();
    mergeSort(arr4, 0, tamanho4 - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tamanho 4: %lf segundos\n", tempo);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);

    return 0;
}

