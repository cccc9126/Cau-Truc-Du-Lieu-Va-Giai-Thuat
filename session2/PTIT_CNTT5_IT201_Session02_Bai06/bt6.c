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
    int addIndex,newNumber;
    do {
        printf("Enter index:");
        scanf("%d",&addIndex);
        if (addIndex<0||addIndex>=n) {
            printf("Index is invalid\n");
        }
    } while (addIndex<0||addIndex>=n);
    printf("Enter new number: ");
    scanf("%d", &newNumber);


    for (int j = n; j > addIndex; j--) {
        arr[j] = arr[j - 1];
    }

    arr[addIndex] = newNumber;
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;

}