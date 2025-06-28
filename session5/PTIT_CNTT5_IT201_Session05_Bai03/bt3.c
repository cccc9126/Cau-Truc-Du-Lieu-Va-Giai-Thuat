//
// Created by Cachiu on 26/6/25.
//
//
// Created by Cachiu on 26/6/25.
//
#include <stdio.h>
int giaiThua(int n) {
    if (n==1) {
        return 1;
    }
    return n*giaiThua(n-1);
}
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("%d",giaiThua(n));
}