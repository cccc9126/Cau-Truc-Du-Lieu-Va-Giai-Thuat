//
// Created by Cachiu on 30/6/25.
//
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;

    do {
        printf("Nhập số lượng phần tử (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int arr[n];

    printf("Nhập %d phần tử:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phần tử arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nMảng trước khi sắp xếp:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("\nMảng sau khi sắp xếp (Insertion Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
