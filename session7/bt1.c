//
// Created by Cachiu on 30/6/25.
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
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
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    bubbleSort(arr, n);

    printf("\nMảng sau khi sắp xếp (Bubble Sort):\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
