//
// Created by Cachiu on 1/7/25.
//
#include <stdio.h>
void linearSearch(int arr[],int n,int x,int start,int end) {
    int mid=(start+end)/2;
    if (arr[mid]==x) {
        printf("So %d tai vi tri arr[%d]",x,mid);
        return;
    }
    if (arr[mid]>x) {
        linearSearch(arr,n,x,start,mid-1);
    }else {
        linearSearch(arr,n,x,mid+1,end);
    }
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
    int x;
    printf("Enter x:");
    scanf("%d",&x);
    int start=0;
    int end=n-1;
    linearSearch(arr,n,x,start,end);
}