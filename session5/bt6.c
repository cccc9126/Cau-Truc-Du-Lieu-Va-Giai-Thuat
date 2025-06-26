//
// Created by Cachiu on 26/6/25.
//
#include <stdio.h>
int sum(int n,int arr[]) {
    if (n==0) {
        return arr[0];
    }
    return arr[n]+sum(n-1,arr);
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

    printf("%d",sum(n-1,arr));
}