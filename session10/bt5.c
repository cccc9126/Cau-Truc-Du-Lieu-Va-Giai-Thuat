
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
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
    return head;
};
Node* removeLastWith(Node*head,int number) {
    Node* current=head;
    Node* pre = (Node*)malloc(sizeof(Node));
    pre->next = head;




    while (pre->next!=NULL) {
        if (pre->next->data==number) {
            Node* temp=pre->next;
            pre->next=pre->next->next;
            free(temp);

        }
        pre=pre->next;
    }
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
    head= removeLastWith(head,15);
    display(head);

}