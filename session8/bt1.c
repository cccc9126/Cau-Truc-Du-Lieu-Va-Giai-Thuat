//
// Created by Cachiu on 1/7/25.
//
#include <stdio.h>


int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x;


    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int arr[n];


    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < n; i++) {
        printf("Phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    printf("Nhập giá trị cần tìm kiếm: ");
    scanf("%d", &x);


    int result = linearSearch(arr, n, x);


    if (result == -1) {
        printf("Không tìm thấy giá trị %d trong mảng.\n", x);
    } else {
        printf("Giá trị %d được tìm thấy tại vị trí chỉ số %d.\n", x, result);
    }


    printf("\nĐộ phức tạp thời gian của thuật toán tìm kiếm tuyến tính là O(n).\n");

    return 0;
}
