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
        printf("Khong the cap phat bo nho cho Node moi.\n");
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
        printf("Khong the cap phat bo nho cho Stack.\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

int main() {
    Stack* myStack = createStack();

    if (myStack != NULL && myStack->top == NULL) {
        printf("Da tao ngan xep thanh cong. Stack dang rong (top = NULL).\n");
    } else {
        printf("Loi khi tao ngan xep.\n");
    }

    free(myStack);
    return 0;
}
