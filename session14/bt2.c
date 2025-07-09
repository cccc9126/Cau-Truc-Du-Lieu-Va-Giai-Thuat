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
    int n;

    for (int i = 5; i >= 1; i--) {
        push(myStack, i);
    }

    printStack(myStack);

    printf("Nhap so nguyen duong muon them vao stack: ");
    scanf("%d", &n);

    if (n > 0) {
        push(myStack, n);
        printStack(myStack);
    } else {
        printf("Chi nhap so nguyen duong.\n");
    }

    Node* temp;
    while (myStack->top != NULL) {
        temp = myStack->top;
        myStack->top = myStack->top->next;
        free(temp);
    }
    free(myStack);

    return 0;
}
