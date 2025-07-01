//
// Created by Cachiu on 1/7/25.
//
#include <stdio.h>
void insertionSort(int arr[],int n) {
    for (int i=0;i<n;i++) {
        int temp=arr[i];
        for (int j=i-1;j>=0;j--) {
            if (arr[j]>temp) {
                arr[j+1]=arr[j];

            }
            arr[j]=temp;
        }

    }
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
}