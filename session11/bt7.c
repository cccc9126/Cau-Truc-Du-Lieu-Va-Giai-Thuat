//
// Created by Cachiu on 4/7/25.
//
//
// Created by Cachiu on 4/7/25.
//
//
// Created by Cachiu on 4/7/25.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
Node* insertLast(Node* head,int data) {
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    if (head==NULL) {
        newNode->prev = NULL;
        return newNode;
    }
    Node* current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
    newNode->next = NULL;
    return head;
};
Node* insertFirst(Node* head, int data) {

    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=head;
    newNode->prev=NULL;
    if (head!=NULL) {
        head->prev = newNode;
    }

    return newNode;
};
Node* removeAt(Node*head,int index) {
  Node* current=head;
    int i=1;
    while (current!=NULL) {
        if (i==index) {
            current->prev->next=current->next;
            current->next->prev=current->prev;
            free(current);
            return head;
        }
        current=current->next;
        i++;

    }
    return head;
};
Node* display(Node*head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL");
    return head;
};
int main() {
    Node* head=NULL;
    head= insertLast(head,5);
    head= insertLast(head,10);
    head= insertLast(head,15);
    head= insertLast(head,20);
    head= insertLast(head,25);
    head= insertFirst(head,0);
head=removeAt(head,2);
    head=display(head);

}