//
// Created by Cachiu on 26/6/25.
//
#include<stdio.h>
void fibonacci(int n,int num1,int num2,int temp) {

    if (n==1) {
        printf("%d",num1);
        return;
    }
    if (n==2) {
        printf("%d ",num1);
        printf("%d",num2);
        return;
    }

    if (temp <= n) {
        printf("%d ", num1 + num2);
        fibonacci(n, num2, num1 + num2, temp + 1);
    }


}
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int num1=0,num2=1;
    int temp=3;
    if (n>=3) {
        printf("%d ",num1);
        printf("%d ",num2);

    }
    fibonacci(n,num1,num2,temp);

}