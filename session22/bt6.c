//
// Created by Cachiu on 24/7/25.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int adjacency[MAX][MAX];
int visited[MAX];
int v, e;

void DFS(int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < v; i++) {
        if (adjacency[start][i] == 1 && !visited[i]) {
            DFS(i);
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
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}
