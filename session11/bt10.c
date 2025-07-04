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
Node* display(Node*head) {
    Node*current=head;
    while (current!=NULL) {
        printf("%d <-> ",current->data);
        current=current->next;
    }
    printf("NULL");
    return head;
};
Node* revertPair(Node*head) {
  Node* current=head;
Node*next=NULL;
    Node*prev=NULL;
    Node*second=NULL;
    Node* newHead = head->next;
    while (current->next!=NULL) {
        second=current->next;
        next=second->next;
        second->prev=prev;
        second->next=current;
        current->prev=second;
        current->next=next;

        if (next != NULL)
            next->prev = current;

        if (prev != NULL)
            prev->next = second;

        prev=current;
        current=next;


    }
    return newHead;
};
int main() {
    Node* head=NULL;
    head= insertLast(head,5);
    head= insertLast(head,10);
    head= insertLast(head,15);
    head= insertLast(head,20);
    head= insertLast(head,25);
head=revertPair(head);
    head=display(head);

}