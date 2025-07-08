//
// Created by Cachiu on 8/7/25.
//
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char data[100];
    int top;
}Stack;
void initStack(Stack* s) {
    s->top=-1;
}
int isFull(Stack* s) {
    return s->top==MAX-1;
}
int isEmpty(Stack* s) {
    return s->top==-1;
}
void push(Stack* s, char x) {
    if (isFull(s)) {
        printf("Stack is full\n");
    }else {
        s->top++;
        s->data[s->top]=x;
    }
}
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    }else {
        return s->data[(s->top)--];


    }
}

void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    }else {
        for (int i=s->top;i>=0;i--) {
            printf("%c ",s->data[i]);
        }
    }
}
void isPalindrome(char *input) {
    Stack s;
    initStack(&s);
    for (int i=0;i<strlen(input);i++) {
        push(&s,input[i]);
    }
    printStack(&s);
    int count=0;
for (int i=0;i<strlen(input);i++) {
    if (input[i]==pop(&s)) {
        count=1;
    }else {
        printf("\nChuỗi không đối xứng");
        return;
    }
}
    if (count==1) {
        printf("\nChuỗi đối xứng");
    }


}
int main() {
    char input[100];
    printf("Nhập chuỗi để kiểm tra: ");
    fgets(input,100,stdin);
    input[strlen(input)-1]='\0';

    isPalindrome(input);


}