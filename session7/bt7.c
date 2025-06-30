//
// Created by Cachiu on 30/6/25.
//
#include <stdio.h>

int main() {
    int n;

    do {
        printf("Nhập số lượng phần tử (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int arr[n], negatives[n], zeros[n], positives[n];
    int negCount = 0, zeroCount = 0, posCount = 0;

    printf("Nhập %d phần tử:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phần tử arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nMảng trước khi sắp xếp:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            negatives[negCount++] = arr[i];
        else if (arr[i] == 0)
            zeros[zeroCount++] = arr[i];
        else
            positives[posCount++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < negCount; i++)
        arr[index++] = negatives[i];
    for (int i = 0; i < zeroCount; i++)
        arr[index++] = zeros[i];
    for (int i = 0; i < posCount; i++)
        arr[index++] = positives[i];

    printf("\nMảng sau khi sắp xếp (âm → 0 → dương):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
