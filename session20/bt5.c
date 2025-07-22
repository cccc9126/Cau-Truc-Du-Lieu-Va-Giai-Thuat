//
// Created by Cachiu on 22/7/25.
//
//
// Created by Cachiu on 22/7/25.
//
//
// Created by Cachiu on 22/7/25.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho cho Node moi.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void display(Node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}Node* addNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    Node** queue = (Node**)malloc(100 * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->left == NULL) {
            current->left = createNode(data);
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = createNode(data);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }
    free(queue);
    return root;
}
int max(Node*root) {
    if (root==NULL) {
        return 0;
    }
    int left=max(root->left);
    int right=max(root->right);
    int max=root->data;
    if (left>max) {
        max=left;
    }
    if (right>max) {
        max=right;
    }
    return max;
}
int main() {
    Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    addNode(root,6);
    display(root);
    printf("\n%d",max(root));

}