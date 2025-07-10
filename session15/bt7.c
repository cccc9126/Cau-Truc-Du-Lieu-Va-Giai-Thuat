//
// Created by Cachiu on 10/7/25.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int isFull(Queue *q) {
    return q->rear >= MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue full, cannot add more.\n");
    } else {
        q->arr[++(q->rear)] = value;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    } else {
        return q->arr[(q->front)++];
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int n, x;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    printf("Nhập dãy số nguyên dương:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (n <= 1) {
        printf("Dãy tăng đều 1 đơn vị (hoặc chỉ có 1 phần tử).\n");
        return 0;
    }

    int prev = dequeue(&q);
    int isIncreasing = 1;

    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        if (curr != prev + 1) {
            isIncreasing = 0;
            break;
        }
        prev = curr;
    }

    if (isIncreasing) {
        printf("Dãy tăng đều 1 đơn vị.\n");
    } else {
        printf("Dãy KHÔNG tăng đều 1 đơn vị.\n");
    }

    return 0;
}
