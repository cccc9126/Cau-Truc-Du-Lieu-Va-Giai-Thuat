//
// Created by Cachiu on 26/6/25.
//
//
// Created by Cachiu on 26/6/25.
//
#include <stdio.h>
void sum(int n,int m,int arr[n][m],int a,int b,int nBlock,int mBlock) {

    if (a==n-1&&b==m-1) {
        arr[n-1][m-1]=arr[n-2][m-1]+arr[m-2][n-1];
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                printf("%d\t",arr[i][j]);
            }
            printf("\n");
        }

        printf("\n%d\n",arr[n-2][m-1]+arr[n-2][m-1]);
        return;
    }

    arr[a][b]=arr[a-1][b]+arr[a][b-1];
    printf("arr[%d][%d]%d\n",a,b,arr[a][b]);
    if (arr[a][b]==arr[nBlock][mBlock]) {
        arr[a][b]=0;
    }
    if (a<n-1) {
        sum(n,m,arr,a+1,b,nBlock,mBlock);
    }
    if (a==n-1) {
        a=1;
        b=b+1;
        sum(n,m,arr,a,b,nBlock,mBlock);
    }






}
int main() {
    int n;
    int m;
    int nBlock,mBlock;

    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter m:");
    scanf("%d",&m);
    int arr[n][m];
    printf("Enter nBlock:");
    scanf("%d",&nBlock);
    printf("Enter mBlock:");
    scanf("%d",&mBlock);
    int a=1;
    int b=1;

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (i==0||j==0) {
                arr[i][j]=1;
            }else {
                arr[i][j]=0;
            }
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    sum(n,m,arr,a,b,nBlock,mBlock);
}