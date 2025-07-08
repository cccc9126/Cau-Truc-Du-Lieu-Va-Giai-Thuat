//
// Created by Cachiu on 8/7/25.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return 0; // hoặc báo lỗi
}
int evaluatePostfix(char expr[]) {
    Stack s;
    initStack(&s);
    int n = strlen(expr);
    for (int i = 0; i < n; i++) {
        if (isdigit(expr[i])) {
            push(&s, expr[i] - '0');
        } else {
            int a = pop(&s);
            int b = pop(&s);
            int result=0;
            switch (expr[i]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}
int main() {
    char expr[100];
    printf("Nhập biểu thức hậu tố (postfix): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0'; // xóa newline

    int result = evaluatePostfix(expr);
    printf("Giá trị biểu thức: %d\n", result);

    return 0;
}
