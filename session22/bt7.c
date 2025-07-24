//
// Created by Cachiu on 24/7/25.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjacency[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int v, e;


void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}


int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}


int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < v; i++) {
            if (adjacency[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            adjacency[i][j] = 0;
        }
    }

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        adjacency[u][w] = 1;
        adjacency[w][u] = 1;
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start);
    printf("\n");

    return 0;
}
