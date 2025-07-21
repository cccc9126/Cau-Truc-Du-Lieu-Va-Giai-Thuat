//
// Created by Cachiu on 21/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

bool isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000, 1000000);
}

int main() {
    Node* root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(20);
    root1->left->left = createNode(2);
    root1->left->right = createNode(7);

    Node* root2 = createNode(10);
    root2->left = createNode(15); // sai vì node trái > node gốc
    root2->right = createNode(5);

    printf("Cây 1 có phải BST không? %s\n", isBST(root1) ? "true" : "false");
    printf("Cây 2 có phải BST không? %s\n", isBST(root2) ? "true" : "false");

    return 0;
}
