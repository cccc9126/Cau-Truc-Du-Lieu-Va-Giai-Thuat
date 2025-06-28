//
// Created by Cachiu on 26/6/25.
//
#include<stdio.h>
#include<string.h>
void palindrome(char str[100],int length,int temp) {
    if (str[temp-length]!=str[length-1]) {
        printf("str is not palindrome");
        return;
    }
    if (str[temp-length]==str[length-1]) {
        if (length==temp/2) {
            printf("str is palindrome");
            return;
        }
        length--;
        return palindrome(str,length-1,temp);
    }
}
int main() {
char str[100];
    printf("Enter str:");
    fgets(str,100,stdin);
    str[strlen(str)-1]='\0';
    int length=strlen(str);

    int temp=length;
    palindrome(str,length,temp);

}