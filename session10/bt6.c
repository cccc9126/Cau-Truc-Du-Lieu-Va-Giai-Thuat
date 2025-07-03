
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;/////
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
    return head;
};
Node* findMid(Node*head) {
    Node* current=head;
    int length=0;
    while (current!=NULL) {
        length++;
        current=current->next;
    }
    int i=0;
    current=head;
    while (current!=NULL&&i<length/2) {
        current=current->next;
        i++;
    }
    printf("Node %d : %d ",i,current->data);
    printf("\n");
    return head;
}
void display(Node* head) {
    Node* current=head;
    while (current!=NULL) {
        printf("%d ",current->data);
        current=current->next;
    }

};

int main() {
    Node* head=NULL;
    head= insertLast(head,5);
    head= insertLast(head,10);
    head= insertLast(head,15);
    head= insertLast(head,20);
    head= insertLast(head,25);


    head= findMid(head);
    display(head);

}
