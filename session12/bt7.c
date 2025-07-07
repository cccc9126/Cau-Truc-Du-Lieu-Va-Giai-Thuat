
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
Node* sort(Node* head) {
    int swapped;
 Node*ptr;
    Node*lptr=NULL;
    do {
        swapped=0;
        ptr=head;
        while (ptr->next!=lptr) {
            if (ptr->data>ptr->next->data) {
                int temp=ptr->data;
                ptr->data=ptr->next->data;
                ptr->next->data=temp;
                swapped=1;
            }
            ptr=ptr->next;
        }
        lptr=ptr;
    }while (swapped);
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
    head= insertLast(head,10);
    head= insertLast(head,5);
    head= insertLast(head,25);
    head= insertLast(head,20);
    head= insertLast(head,15);
    head=sort(head);
    display(head);
}