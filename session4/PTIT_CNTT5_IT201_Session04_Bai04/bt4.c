//
// Created by Cachiu on 25/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
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
    int number;
    printf("Enter number:");
    scanf("%d",&number);
    for (int i=n-1;i>=0;i--) {
        if (arr[i]==number) {
            printf("So %d tai vi tri arr[%d]",number,i);
            return 0;
        }
    }
    printf("Khong ton tai");
    return 0;
}
