//
// Created by Cachiu on 16/6/25.
//
#include<stdio.h>
int main () {
    int number=5;
    int arr[10]={1,2,5,4,5,6,7,8,9,10};
    int count=0;
    for (int i=0;i<10;i++) {
        if (arr[i]==number) {
            count++;
        }
    }
}
/*
 * time complexity: O(n)
 * space complexity: O(1)
 */