//
// Created by Cachiu on 16/6/25.
//
#include<stdio.h>
int main() {
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            printf("%d\n",arr[i][j]);
        }
    }
}/*
time complexity: O(n^2)
space complexity:O(1)
*/