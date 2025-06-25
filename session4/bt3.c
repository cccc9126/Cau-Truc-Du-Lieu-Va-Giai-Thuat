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
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int min=arr[0];

    for (int i=0;i<n;i++) {

        if (arr[i]<min) {
            min=arr[i];
        }
    }
    printf("Min la %d",min);
    return 0;
}