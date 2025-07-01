//
// Created by Cachiu on 1/7/25.
//
#include <stdio.h>
void selectionSort(int arr[], int n){
    for (int i=0;i<n;i++) {
        int minIndex=i;
        for (int j=i+1;j<n;j++) {
            if (arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main() {

    int n;

    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < n; i++) {
        printf("Phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    selectionSort(arr,n);

    printf("Mảng sau khi sắp xếp tăng dần là:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}