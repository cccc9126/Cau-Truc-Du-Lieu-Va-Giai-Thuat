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

    for (int i = 0; i < n; i++) {
        adjacency[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1 && j > i) {
                addEdge(i, j);
            }
        }
    }

    printf("Danh sách kề:\n");
    printAdjList(n);

    return 0;
}
