#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

char peek(Stack* s) {
    return s->data[s->top];
}

void push(Stack* s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack* s) {
    if (!isEmpty(s))
        return s->data[(s->top)--];
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    init(&s);
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isspace(c)) continue;

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else { // toán tử
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    // pop còn lại
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Nhập biểu thức infix (trung tố): ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("Biểu thức postfix là: %s\n", postfix);
    return 0;
}
