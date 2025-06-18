//
// Created by Cachiu on 17/6/25.
//
#include <stdio.h>
int main() {
    int n;

    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];

    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n/2;i++) {
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}