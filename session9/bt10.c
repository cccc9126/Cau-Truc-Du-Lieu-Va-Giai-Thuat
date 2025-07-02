//
// Created by Cachiu on 2/7/25.
//
//
// Created by Cachiu on 2/7/25.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;
//thêm node
Node* insertFirst(Node* head,int data) {
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=head;
    return newNode;
}
Node* insertLast(Node* head,int data) {
    Node* newNode= (Node*)malloc(sizeof(Node));
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
    return head;
}
Node* insertAt(Node* head,int index, int data) {
    if (index<0) {
        printf("Index is valid");
        return head;
    }
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=data;
    if (index==0) {
        newNode->next=head;
        return head;
    }
    Node* current=head;
    int i=0;
    while (i<index-1 && current!=NULL) {
        current=current->next;
        i++;
    }
    newNode->next=current->next;
    current->next=newNode;
    return head;
}
int length(Node* head) {
    int count=0;
    while (head!=NULL) {
        count++;
        head=head->next;
    }
    return count;
}
Node* revertPair(Node* head) {
    int i=0;
    Node* current=head;
    while (current!=NULL) {
        current=current->next;
        if (i%2==1) {
            Node* temp=current->next;
            current->next=current->next->next;
            temp->next=current;
            current=temp;
        }
        i++;

    }
    return head;
}
void print(Node* head) {
    while (head!=NULL) {

        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head=NULL;
    head=insertFirst(head,5);
    head=insertFirst(head,10);
    head=insertFirst(head,15);
    head=insertLast(head,0);

    head=revertPair(head);
    print(head);


}