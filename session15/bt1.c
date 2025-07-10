//
// Created by Cachiu on 10/7/25.
//
#include <stdio.h>
#define MAX 100
typedef struct {
    int arr[100];
    int front;
    int rear;
}Queue;
void initQueue(Queue* queue){
    queue->front=0;
    queue->rear=-1;
}
int isEmpty(Queue* queue){
        return queue->front>queue->rear;
}
int isFull(Queue* queue) {
    return queue->rear>MAX-1;
}
void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    } else {
        queue->arr[++(queue->rear)]=data;
    }
}
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        queue->front++;
    }
}
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {}
}
void display(Queue* queue) {
    for (int i=queue->front;i<=queue->rear;i++) {
        printf("%d ",queue->arr[i]);
    }
}
int main() {
    Queue q;
    initQueue(&q);

    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    }

    if (!isFull(&q)) {
        printf("Queue is not full\n");
    }
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    dequeue(&q);
    display(&q);
    return 0;
}