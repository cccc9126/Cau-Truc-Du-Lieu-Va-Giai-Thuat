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
#include <stdlib.h>
void sum(int n,int m,int arr[n][m]) {
    int sum1=0;
    int sum2=0;
    for (int i=0;i<n;i++) {
        sum1+=arr[i][i];
        sum2+=arr[i][m-i-1];
    }


    printf("Sum1=%d\n",sum1);
    printf("Sum2=%d\n",sum2);
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
    if (n!=m) {
        printf("Khong co duong cheo chinh va phu");
        return 0;
    }

    int arr[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            printf("arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    sum(n,m,arr);



}