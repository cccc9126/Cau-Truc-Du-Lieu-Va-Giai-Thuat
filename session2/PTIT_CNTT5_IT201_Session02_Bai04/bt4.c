//
// Created by Cachiu on 17/6/25.
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
    int fixIndex,newNumber;
do {
    printf("Enter index:");
    scanf("%d",&fixIndex);
    if (fixIndex<0||fixIndex>=n) {
        printf("Index is invalid\n");
    }
}
    while (fixIndex<0||fixIndex>=n);
    printf("Enter new number:");
    scanf("%d",&newNumber);
    arr[fixIndex]=newNumber;
for (int i=0;i<n;i++) {
    printf("%d ",arr[i]);
}
}