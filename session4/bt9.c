//
// Created by Cachiu on 25/6/25.
//
#include <stdio.h>
void search( int arr[], int start, int end, int number) {

        int mid = start + (end - start) / 2;
        if (arr[mid] == number) {
            printf("so %d tai vi tri %d\n", number, mid);
            return;
        }
        if (arr[mid] < number) {
            return search( arr, mid + 1, end, number);
        }

        else {
            return search( arr, start, mid - 1, number);
        }


    printf("so %d khong tìm thay\n", number);
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
    int start=0;
    int end=n-1;
    int number;
    printf("Enter number:");
    scanf("%d",&number);
    search( arr, start, end, number);

    return 0;
}