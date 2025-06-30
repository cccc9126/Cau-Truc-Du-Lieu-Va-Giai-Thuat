//
// Created by Cachiu on 30/6/25.
//
#include <stdio.h>
#include <stdlib.h>

int absDiff(int a, int x) {
    return abs(a - x);
}

void customSort(int a[], int n, int x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int d1 = absDiff(a[i], x);
            int d2 = absDiff(a[j], x);

            if (d1 > d2 || (d1 == d2 && a[i] > a[j])) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n, x;

    do {
        printf("Nhập số lượng phần tử (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    int a[n];

    printf("Nhập %d phần tử:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Nhập giá trị X: ");
    scanf("%d", &x);

    customSort(a, n, x);

    printf("\nMảng sau khi sắp xếp theo khoảng cách tới %d:\n", x);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
