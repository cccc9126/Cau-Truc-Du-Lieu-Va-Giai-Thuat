#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

void check(char *input) {
    Stack s;
    initStack(&s);
    
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s) || !isMatching(peek(&s), c)) {
                printf("Chuỗi KHÔNG hợp lệ (sai cặp ngoặc)\n");
                return;
            } else {
                pop(&s);
            }
        }
    }

    if (isEmpty(&s)) {
        printf("Chuỗi HỢP LỆ \n");
    } else {
        printf("Chuỗi KHÔNG hợp lệ \n");
    }
}

int main() {
    char input[100];
    printf("Nhập chuỗi để kiểm tra: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    check(input);

    return 0;
}
