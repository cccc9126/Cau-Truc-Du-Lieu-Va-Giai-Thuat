//
// Created by Cachiu on 8/7/25.
//
//
// Created by Cachiu on 8/7/25.
//
#include <stdio.h>
#define MAX 100
typedef struct {
    int data[100];
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

void push(Stack* s, int x) {
    if (isFull(s)) {
        printf("Stack is full\n");
    }else {
        s->top++;
        s->data[s->top]=x;
    }
}
void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    }else {
        s->top--;
    }
}
void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    }else {
        for (int i=s->top;i>=0;i--) {
            printf("%d ",s->data[i]);
        }
    }
}
int main() {
    Stack s;
    initStack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    push(&s,60);
    pop(&s);
    printStack(&s);
}