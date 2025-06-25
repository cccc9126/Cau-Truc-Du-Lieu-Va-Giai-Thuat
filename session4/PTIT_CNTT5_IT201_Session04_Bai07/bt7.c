//
// Created by Cachiu on 25/6/25.
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
    int count=0;
    for (int i=0;i<n/2;i++) {
        if (arr[i]==arr[n-1-i]) {
            printf("cap doi xung la (%d,%d)",arr[i],arr[n-i-1]);
            count++;
        }
    }
    if (count==0) {
        printf("Khong co cap doi xung");
    }
    return 0;
}