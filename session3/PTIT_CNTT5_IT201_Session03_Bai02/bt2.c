//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    do{
        printf("Do dai cua mang :");
        scanf("%d",&n);
        if(n<0){
            printf("Nhap lai");
        }
    }while(n<0);

    int* arr=malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Khong the tao mang");
        return 0;
    }
    for(int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d :",i+1);
        scanf("%d",&arr[i]);
    }

    int max=arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    printf("Max la %d",max);
    free(arr);
    return 0;

}