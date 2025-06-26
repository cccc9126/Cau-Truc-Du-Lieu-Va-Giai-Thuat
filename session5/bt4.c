//
// Created by Cachiu on 26/6/25.
//
#include <stdio.h>
int sum(int n,int m) {
    if (m-1==n) {
        return m+n;
    }
    return m+sum(n,m-1);
}
int main() {
    int firstNumber,secondNumber;
    printf("Enter first number:");
    scanf("%d",&firstNumber);
    printf("Enter second number:");
    scanf("%d",&secondNumber);
printf("%d",sum(firstNumber,secondNumber));
}