//
// Created by Cachiu on 11/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TILE_MAX 100

typedef struct Course {
    int id;
    char title[TILE_MAX];
    int creidt;
} Course;

typedef struct Node1 {
    Course course;
    struct Node1 *next;
} Node1;

typedef struct Node2 {
    Course course;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

Node1 *addCourse(Node1 *head, int *id) {
    char title[TILE_MAX];
    int credit = -1;
    while (getchar() != '\n' && getchar() != EOF);
    printf("Enter course title: ");
    fgets(title, TILE_MAX, stdin);
    title[strcspn(title, "\n")] = '\0';


    while (credit < 0 || credit > 100) {
        printf("Enter course credit: ");
        scanf("%d", &credit);
        if (credit < 0 || credit > 100) {
            printf("Invalid credit. Please enter a valid credit.\n");
        }
    }


    Node1 *newNode = (Node1 *) malloc(sizeof(Node1));
    newNode->course.id = ++*id;
    strcpy(newNode->course.title, title);
    newNode->course.creidt = credit;
    if (head == NULL) {
        head = newNode;
        return head;
    } else {
        Node1 *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

Node1 *deleteCourse(Node1 *head, int id) {
    int dltId;
    do {
        printf("Enter course id: ");
        scanf("%d", &dltId);
        if (dltId < 0 || dltId > id) {
            printf("Invalid id. Please enter a valid id.\n");
        }
    } while (dltId < 0 || dltId > id);
    if (dltId == 0) {
        Node1 *temp = head;
        head = head->next;
        free(temp);
        return head;
    } else if (dltId == id) {
        Node1 *current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node1 *temp = current->next;
        current->next = NULL;
        free(temp);
        return head;
    } else {
        Node1 *current = head;
        for (int i = 0; i < dltId - 1; i++) {
            current = current->next;
        }

        Node1 *temp = current->next;
        current->next = current->next->next;
        free(temp);
        return head;
    }
}

void display(Node1 *head) {

    Node1 *current = head;
    printf("=====================\n");
    while (current != NULL) {
        printf("ID: %d | TITLE: %s \nCREDIT: %d\n", current->course.id, current->course.title, current->course.creidt);
        current = current->next;
    }
    printf("=====================\n");
    int out;
    while (out!=0) {
        printf("Enter 0 to exit: ");
        scanf("%d", &out);
        if (out==0) break;
    }
}
Node1* updateCourse(Node1* head, int id) {
        int updareId;
        char updateTitle[TILE_MAX];
        int updateCredit=-1;
        do {
            printf("Enter course id: ");
            scanf("%d", &updareId);
            if (updareId < 0 || updareId > id) {
                printf("Invalid id. Please enter a valid id.\n");
            }
        } while (updareId < 0 || updareId > id);

    Node1* current = head;
    for (int i = 0; i < updareId; i++) {
        current = current->next;
    }
    printf("ID: %d | TITLE: %s \nCREDIT: %d\n", current->course.id, current->course.title, current->course.creidt);

    while (getchar() != '\n');
    printf("Enter new course title: ");
    fgets(updateTitle, TILE_MAX, stdin);
    updateTitle[strcspn(updateTitle, "\n")] = '\0';

    while (updateCredit < 0 || updateCredit > 100) {
        printf("Enter new course credit: ");
        scanf("%d", &updateCredit);
        if (updateCredit < 0 || updateCredit > 100) {
            printf("Invalid credit. Please enter a valid credit.\n");
        }
    }
    current->course.creidt = updateCredit;
    strcpy(current->course.title, updateTitle);
    return head;
}
void sell(Node1 *head, Node2 *head2) {
    Node1 *current = head;
    while (current != NULL) {
        Node2 *newNode = (Node2 *) malloc(sizeof(Node2));
        newNode->course.id = current->course.id;
        strcpy(newNode->course.title, current->course.title);
        newNode->course.creidt = current->course.creidt;
        newNode->next = NULL;
        newNode->prev = NULL;

    }
}
void sortByCredit(Node1 *head) {
    if (head == NULL || head->next == NULL) return;

    int swapped;
    Node1 *ptr;
    Node1 *lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->course.creidt > ptr->next->course.creidt) {
                Course temp = ptr->course;
                ptr->course = ptr->next->course;
                ptr->next->course = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

int main() {
    int id = -1;
    int choice;
    Node1 *head = NULL;
    Node2 *head2 = NULL;
    do {
        printf("===========MENU===========\n");
        printf("1.Add course\n");
        printf("2.Display course\n");
        printf("3.Delete course\n");
        printf("4.Update course\n");
        printf("5.Sell\n");
        printf("6.Sort course\n");
        printf("7.Search course\n");
        printf("8.Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = addCourse(head, &id);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = deleteCourse(head, id);
                break;
            case 4:
                head=updateCourse(head,id);
                break;

            case 5:
                head=sell(head,head2);
                break;
            case 6:
                sortByCredit(head);
                break;
            case 7:
                break;
            default:
                break;
        }
    } while (choice != 8);
}
