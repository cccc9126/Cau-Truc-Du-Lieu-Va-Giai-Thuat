//
// Created by Cachiu on 23/7/25.
//
//
// Created by Cachiu on 23/7/25.
//
#include<stdio.h>
int matrix[4][4];
void matrixs() {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            matrix[i][j]=0;
        }
    }
}
void adjacency(int U, int V) {
    matrix[U][V]=1;
    matrix[V][U]=1;
}
void display() {
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    matrixs();
    adjacency(0,1);
    display();
}