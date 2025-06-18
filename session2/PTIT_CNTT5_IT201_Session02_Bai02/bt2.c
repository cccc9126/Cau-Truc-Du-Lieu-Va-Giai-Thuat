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

    int number;
    printf("Enter number:");
    scanf("%d",&number);
    int count=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==number) {
            count++;
        }
    }
    if (count==0) {
        printf("Khong co so nguyen to");
        return 0;
    }
    printf("%d\n",count);
    return 0;
}