//
// Created by Cachiu on 16/6/25.
//
#include<stdio.h>
#include <string.h>
int main() {
    char str[6]="hello";
    char str2[6]="olleh";
    for (int i=0;i<(5/2);i++) {
        char temp=str[i];
        str[i]=str[5-1-i];
        str[5-1-i]=temp;
    }
    printf("%s\n",str);
    if (strcmp(str, str2) == 0) {
        printf("Hai chuỗi là hoán vị đảo ngược của nhau.\n");
    } else {
        printf("Hai chuỗi KHÔNG phải hoán vị đảo ngược.\n");
    }
}
/*
 * time complexity: O(n)
 * space complexuty: O(1)
 */