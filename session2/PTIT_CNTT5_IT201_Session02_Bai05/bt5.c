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
    int deleteIndex;
    do {
        printf("Enter index:");
        scanf("%d",&deleteIndex);
        if (deleteIndex<0||deleteIndex>=n) {
            printf("Index is invalid\n");
        }
    }
    while (deleteIndex<0||deleteIndex>=n);
    for (int i=deleteIndex;i<n-1;i++) {
        arr[i]=arr[i+1];
    }
    for (int i=0;i<n-1;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}