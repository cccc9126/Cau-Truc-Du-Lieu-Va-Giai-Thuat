//
// Created by Cachiu on 20/6/25.
//
//
// Created by Cachiu on 20/6/25.
//
#include <stdio.h>
#include <stdlib.h>
void find(int n,int m,int arr[n][m]) {
    int max=arr[0][0];
    int min=arr[0][0];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j]>max) {
                max=arr[i][j];
            }
            if (arr[i][j]<min) {
                min=arr[i][j];
            }
        }
    }
    printf("Max: %d\nMin: %d\n",max,min);
}
int main() {
    int n,m;
    do {
        printf("Enter n:");
        scanf("%d",&n);
        printf("Enter m:");
        scanf("%d",&m);
        if (n<0||m<0) {
            printf("Invalid input\n");
        }
        if (n==0||m==0) {
            printf("Invalid input\n");
        }
    }
    while (n<=0||m<=0);

    int arr[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            printf("arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    find(n,m,arr);



}