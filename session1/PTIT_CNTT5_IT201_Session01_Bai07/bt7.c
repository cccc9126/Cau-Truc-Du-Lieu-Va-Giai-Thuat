//
// Created by Cachiu on 16/6/25.
//
#include<stdio.h>
int main() {
    int arr[5]={1,2,2,3,4};
    int length=0;
    int unique[length];
    for (int i=0;i<5;i++) {
        int count =0;
        for (int j=0;j < length;j++) {
            if (unique[j]==arr[i]) {
                count++;
            }
        }
        if (count==0) {
            unique[length]=arr[i];
            length++;
        }
    }
    if (length<5) {
        printf("mang co so trung lap");
    }

    return 0;


}
/*
 * time complexity:O(n^2)
 * space complexity: O(n)
 */