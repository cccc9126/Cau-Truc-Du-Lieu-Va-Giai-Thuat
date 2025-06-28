//
// Created by Cachiu on 27/6/25.
//
#include <stdio.h>
void find(int n,int arr[],int index,int max,int min) {
    if (index==n) {
        printf("Max la %d",max);
        printf("Min la %d",min);
        return;
    }
    if (arr[index]>max) {
        max=arr[index];

    }if (arr[index]<min) {
        min=arr[index];
    }
    find(n,arr,index+1,max,min);
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
    int max=arr[0];
    int min=arr[0];
    int index=0;
    find(n,arr,index,max,min);
}