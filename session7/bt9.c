//
// Created by Cachiu on 30/6/25.
//
#include <stdio.h>

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int n;

    do {
        printf("Nhập số lượng phần tử (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int arr[n], even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    printf("Nhập %d phần tử:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            even[evenCount++] = arr[i];
        else
            odd[oddCount++] = arr[i];
    }

    sortAscending(even, evenCount);
    sortDescending(odd, oddCount);

    int index = 0;
    for (int i = 0; i < evenCount; i++)
        arr[index++] = even[i];
    for (int i = 0; i < oddCount; i++)
        arr[index++] = odd[i];

    printf("\nMảng sau khi sắp xếp (chẵn ↑ | lẻ ↓):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
