//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
#include <stdio.h>
#include <stdlib.h>
void averge(int* arr,int n) {
    int sum=0;
    int count=0;
    for (int i=0;i<n;i++) {
        if (arr[i]%2==0) {
            sum+=arr[i];
            count++;
        }
    }
    if (count!=0) {
        printf("So tung cac so chan cua mang la %d",sum/count);
    }else{
        printf("Khong co so chan");
    }
}

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
     averge( arr,n);
    free(arr);

}