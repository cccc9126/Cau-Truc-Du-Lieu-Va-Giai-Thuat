//
// Created by Cachiu on 26/6/25.
//
#include <stdio.h>
void print(int n,int number) {

    if (n<number) {
        return;
    }

    printf("%d ",number);
    number++;
    return print(n,number);
}
int main() {
    int n;
    int number=1;
    printf("Enter number:");
    scanf("%d",&n);
print(n,number);
}