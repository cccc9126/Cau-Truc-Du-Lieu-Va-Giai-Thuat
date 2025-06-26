//
// Created by Cachiu on 26/6/25.
//
#include<stdio.h>
#include<string.h>
void transform(char str[], int length, int index) {
    if (index == length) {
        return;
    }

    if (index == 0) {

        if (str[index] == '+') {
            transform(str, length, index + 1);
        }
        else if (str[index] == '-') {
            printf("-");
            transform(str, length, index + 1);
        }
        else if (str[index] >= '0' && str[index] <= '9') {
            printf("%c", str[index]);
            transform(str, length, index + 1);
        }
        else {
            printf("Invalid character");
            return;
        }
    }
    else {

        if (str[index] >= '0' && str[index] <= '9') {
            printf("%c", str[index]);
        }
        else {
            printf("Invalid character");
            return;
        }
        transform(str, length, index + 1);
    }
}

int main() {
    char str[100];
    printf("Enter str:");
    fgets(str,100,stdin);
    str[strlen(str)-1]='\0';
    int length=strlen(str);
    int index=0;
    transform(str,length,index);
}
