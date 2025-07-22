//
// Created by Cachiu on 22/7/25.
//
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

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void deleteDeepest(Node* root, Node* delNode) {
    if (root == NULL) return;
    if (root->left == delNode) {
        root->left = NULL;
        free(delNode);
        return;
    }
    if (root->right == delNode) {
        root->right = NULL;
        free(delNode);
        return;
    }
    if (root->left) deleteDeepest(root->left, delNode);
    if (root->right) deleteDeepest(root->right, delNode);
}


void deleteNode(Node* root, int key) {
    if (root == NULL) {
        printf("Cay rong.\n");
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            root = NULL;
            return;
        } else {
            printf("Khong tim thay gia tri %d.\n", key);
            return;
        }
    }

    Node* keyNode = NULL;
    Node* temp = NULL;
    Node* last = NULL;


    Node** queue = (Node**)malloc(100 * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == key) keyNode = temp;
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    last = temp;

    if (keyNode != NULL) {
        keyNode->data = last->data;
        deleteDeepest(root, last);
    } else {
        printf("Khong tim thay gia tri %d trong cay.\n", key);
    }

    free(queue);
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Cay truoc khi xoa:\n");
    inorder(root);

    deleteNode(root, 2);  // xóa node có giá trị 2

    printf("\nCay sau khi xoa:\n");
    inorder(root);

    return 0;
}
