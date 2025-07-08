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
   
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
        push(&s,arr[i]);
    }
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
       
    }
    printf("\n");
    printStack(&s);
   
}