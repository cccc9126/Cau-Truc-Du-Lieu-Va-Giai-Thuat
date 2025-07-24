//
// Created by Cachiu on 24/7/25.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjacency[MAX];

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* node = createNode(v);
    node->next = adjacency[u];
    adjacency[u] = node;

    node = createNode(u);
    node->next = adjacency[v];
    adjacency[v] = node;
}

void printAdjList(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* current = adjacency[i];
        while (current != NULL) {
            printf(" %d ->", current->data);
            current = current->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n = 5;


    int matrix[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };
    int sum=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum+=matrix[i][j];
        }
    }
    printf("So canh cua ma tran la %d", sum/2);

    return 0;
}
