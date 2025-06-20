//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
#include <stdio.h>
#include <stdlib.h>

void sum(int n, int m, int arr[n][m]) {
    int sum = 0;
    int k;
    do {
        printf("Enter k:");
        scanf("%d", &k);
        if (k <= 0 || k > n) {
            printf("Invalid input\n");
        }
    } while (k <= 0 || k > n);
    for (int i = 0; i < m; i++) {
        sum += arr[k - 1][i];
    }
    printf("Sum=%d", sum);
}

int main() {
    int n, m;
    do {
        printf("Enter n:");
        scanf("%d", &n);
        printf("Enter m:");
        scanf("%d", &m);
        if (n < 0 || m < 0) {
            printf("Invalid input\n");
        }
        if (n == 0 || m == 0) {
            printf("Invalid input\n");
        }
    } while (n <= 0 || m <= 0);


    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("arr[%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    sum(n, m, arr);
}
