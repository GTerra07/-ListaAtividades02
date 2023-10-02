#include <stdio.h>

void insertionSortDecrescente(int arr[], int n) {
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenacao por insercao decrescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSortDecrescente(arr, n);

    printf("\nArray depois da ordenacao por insercao decrescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

