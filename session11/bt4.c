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
Node* search(Node*head,int data) {
    Node*current=head;
    int i=0;
    while (current!=NULL) {
        if (current->data==data) {
            printf("\nNode %d : %d",i,current->data);

            return current;
        }
        current=current->next;
        i++;
    }
    return NULL;
}
int length(Node* head) {
    Node* current=head;
    int length=0;
    while (current!=NULL) {
        length++;
        current=current->next;
    }
    return length;
}
int main() {
    Node* head=NULL;
    head= insertLast(head,5);
    head= insertLast(head,10);
    head= insertLast(head,15);
    head= insertLast(head,20);
    head= insertLast(head,25);

    head=display(head);

    printf("\nLength:%d ",length(head));

}