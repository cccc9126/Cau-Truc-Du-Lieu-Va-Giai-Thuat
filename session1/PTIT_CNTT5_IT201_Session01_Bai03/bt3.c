//
// Created by Cachiu on 16/6/25.
//
#include<stdio.h>
#include <stdlib.h>

int main() {
    int* arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        arr[i]=i;
    }
    return arr;
}
/*
 * space complexity: O(n)
 */
