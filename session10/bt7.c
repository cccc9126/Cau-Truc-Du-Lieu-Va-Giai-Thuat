//
// Created by Cachiu on 3/7/25.
//

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

void display(Node* head) {
    Node* current=head;
    while (current!=NULL) {
        printf("%d ",current->data);
        current=current->next;
    }

};

Node* sort(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    int swapped;
    Node* ptr;
    Node* last = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                // Hoán đổi giá trị
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;  // Lần sau không cần xét lại node này nữa
    } while (swapped);

    return head;
}
int main() {
    Node* head=NULL;
    head= insertLast(head,20);
    head= insertLast(head,10);
    head= insertLast(head,15);
    head= insertLast(head,25);
    head= insertLast(head,5);

    head =sort(head);
    display(head);

}
