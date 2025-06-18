//
// Created by Cachiu on 16/6/25.
//
#include<stdio.h>
int main () {
    int arr[5]={4,5,7,3,1};
    for (int i=0;i<5-1;i++) {
        for (int j=0;j<5-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
/*
 *time complexity: O(n^2)
 *space complexity: O(1)
 */