//
// Created by Cachiu on 8/7/25.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char* data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char* str) {
    s->data[++(s->top)] = str;
}

char* pop(Stack* s) {
    return s->data[(s->top)--];
}

char* postfixToInfix(char* expr) {
    Stack s;
    initStack(&s);
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isalnum(c)) {

            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = c;
            operand[1] = '\0';
            push(&s, operand);
        } else {

            char* op2 = pop(&s);
            char* op1 = pop(&s);


            char* newExpr = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            sprintf(newExpr, "(%s%c%s)", op1, c, op2);

            push(&s, newExpr);


            free(op1);
            free(op2);
        }
    }

    return pop(&s);
}
