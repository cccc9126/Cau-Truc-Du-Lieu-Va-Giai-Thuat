//
// Created by Cachiu on 21/7/25.
//
#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert( int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(Node *root) {
    if (root == NULL) {
        return;

    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
}
int main() {
    Node *root = NULL;
    root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    root->left->left=insert(4);
    root->left->right=insert(5);
    inorder(root);
}
