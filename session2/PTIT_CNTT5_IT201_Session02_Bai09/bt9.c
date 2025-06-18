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
    int max=arr[0];
    int maxCount=1;
    for (int i=0;i<n;i++) {
        int count=0;
        for (int j=i+1;j<n;j++) {
            if (arr[i]==arr[j]) {
                count++;
            }
        }
        printf("count[%d] = %d\n",i,count);
        if (count>maxCount) {
            maxCount=count;
            max=arr[i];
        }
    }
    printf("so xuat hien nhieu nhat la : %d",max);
}