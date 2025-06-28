//
// Created by Cachiu on 27/6/25.
//
#include <stdio.h>
void transBinary(int n,int arr[],int *index) {
    if (n==0) {
        return;
    }
    arr[*index]=n%2;
    (*index)++;
    transBinary(n/2,arr,index);
}
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[100];
    int index=0;
    transBinary(n,arr,&index);
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");


}