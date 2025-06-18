//
// Created by Cachiu on 17/6/25.
//
#include<stdio.h>
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];

    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int sumOfNumber;
    printf("Enter sum:");
    scanf("%d",&sumOfNumber);
    int count=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]+arr[j]==sumOfNumber) {
                printf("arr[%d]+arr[%d] = %d\n",i,j,arr[i]+arr[j]);
                count++;
            }
        }
    }
    if (count==0) {
        printf("Don't have any number");
    }
    return 0;
}