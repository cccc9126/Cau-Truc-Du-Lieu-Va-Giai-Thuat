//
// Created by Cachiu on 17/6/25.
//
#include <stdio.h>
int main () {
    int n;

    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];

    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for (int i=0;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
        }
    }
    printf("%d\n",max);
    return 0;
}