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
    for(int i=0;i<n;i++){
        printf("Nhap phan tu thu %d :",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

int *temp=realloc(arr,n*2*sizeof(int));
    if(temp==NULL){
        printf("Khong the tao mang");
        return 0;
    }
    printf("\n");
    for(int i=n;i<n*2;i++){
        printf("Nhap phan tu thu %d :",i+1);
        scanf("%d",&temp[i]);
    }
    for(int i=0;i<n*2;i++){
        printf("%d ",temp[i]);
    }
    free(temp);

}