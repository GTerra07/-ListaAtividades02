#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int trocou;

    do {
        trocou = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Troca os elementos
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocou = 1;
            }
        }
    } while (trocou);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenacao por bolha:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nArray depois da ordenacao por bolha:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

