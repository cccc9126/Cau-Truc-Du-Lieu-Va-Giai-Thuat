//
// Created by Cachiu on 22/7/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findLevel(Node* root, int value, int level) {
    if (root == NULL) return -1;

    if (root->data == value)
        return level;

    int leftLevel = findLevel(root->left, value, level + 1);
    if (leftLevel != -1)
        return leftLevel;

    return findLevel(root->right, value, level + 1);
}



int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int value = 3;
    int level = findLevel(root, value, 0);

    if (level != -1)
        printf("Node level: %d\n", level);
    else
        printf("Không tìm thấy node có giá trị %d\n", value);

    return 0;
}
