//
// Created by Cachiu on 7/7/25.
//
#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* insertLast(Node* head,int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if (head==NULL) {
        return newNode;
    }
    Node* current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    return head;
}
Node* removeLast(Node*head) {
    if (head==NULL) {
        return NULL;
    }
    if (head->next==NULL) {
        free(head);
        return NULL;
    }
    Node* current=head;
    while (current->next->next!=NULL) {
        current=current->next;
    }
    current->next=NULL;
    free(current->next);
    return head;

}
void display(Node* head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL");
}
int main() {
    Node* head=NULL;
    head= insertLast(head,5);
    head= insertLast(head,10);
    head= insertLast(head,15);
    head= insertLast(head,20);
    head= insertLast(head,25);
    removeLast(head);
    display(head);
}