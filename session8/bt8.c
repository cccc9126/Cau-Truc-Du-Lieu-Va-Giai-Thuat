//
// Created by Cachiu on 1/7/25.
//
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    printf("\nMảng ban đầu: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Mảng sau khi sắp xếp (Insertion Sort): ");
    printArray(arr, n);

    printf("\nNhập giá trị cần tìm: ");
    scanf("%d", &x);

    int linearResult = linearSearch(arr, n, x);
    int binaryResult = binarySearch(arr, n, x);

    if (linearResult != -1)
        printf("Tìm kiếm tuyến tính: Tìm thấy %d tại vị trí %d\n", x, linearResult);
    else
        printf("Tìm kiếm tuyến tính: Không tìm thấy %d trong mảng\n", x);

    if (binaryResult != -1)
        printf("Tìm kiếm nhị phân: Tìm thấy %d tại vị trí %d\n", x, binaryResult);
    else
        printf("Tìm kiếm nhị phân: Không tìm thấy %d trong mảng\n", x);

    return 0;
}
