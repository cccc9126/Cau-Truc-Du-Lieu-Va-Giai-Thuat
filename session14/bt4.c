//
// Created by Cachiu on 9/7/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Khong the cap phat bo nho.\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    if (!newNode) return;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack rong.\n");
        return -1;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("stack = {\n  ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");
}

int main() {
    Stack* myStack = createStack();

    for (int i = 5; i >= 1; i--) {
        push(myStack, i);
    }

    printStack(myStack);

    int removed = pop(myStack);
    if (removed != -1) {
        printf("Phan tu lay ra: %d\n", removed);
        printStack(myStack);
    }

    while (myStack->top != NULL) {
        Node* temp = myStack->top;
        myStack->top = myStack->top->next;
        free(temp);
    }
    free(myStack);

    return 0;
}
