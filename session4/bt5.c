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
    int start=0;
    int end=n-1;
    int number;
    printf("Enter number:");
    scanf("%d",&number);
    while (start<=end) {
        int mid=(start+end)/2;
        if (arr[mid]==number) {
            printf("So %d tai vi tri arr[%d]",number,mid);
            return 0;
        }
        if (arr[mid]<number) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    return 0;
}