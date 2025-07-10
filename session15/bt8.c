//
// Created by Cachiu on 10/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 31

typedef struct {
    char name[NAME_LEN];
    int age;
} Customer;

typedef struct {
    Customer arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}


int isFull(Queue *q) {
    return q->rear >= MAX - 1;
}


void enqueue(Queue *q, char name[], int age) {
    if (isFull(q)) {
        printf("Hàng đợi đã đầy, không thể thêm khách.\n");
        return;
    }
    q->rear++;
    strncpy(q->arr[q->rear].name, name, NAME_LEN - 1);
    q->arr[q->rear].name[NAME_LEN - 1] = '\0';
    q->arr[q->rear].age = age;
}

void serve(Queue *q) {
    if (isEmpty(q)) {
        printf("Không có khách trong hàng đợi này.\n");
        return;
    }
    Customer c = q->arr[q->front++];
    printf("Phục vụ khách: %s (Tuổi: %d)\n", c.name, c.age);
}


void displayQueue(Queue *q, char *label) {
    printf("== %s ==\n", label);
    if (isEmpty(q)) {
        printf("  (trống)\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("  - %s (Tuổi: %d)\n", q->arr[i].name, q->arr[i].age);
    }
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    char name[NAME_LEN];
    int age;

    do {
        printf("\n===== NGÂN HÀNG =====\n");
        printf("1. Thêm khách hàng\n");
        printf("2. Phục vụ 1 khách\n");
        printf("3. Hiển thị hàng đợi\n");
        printf("4. Thoát\n");
        printf("Chọn thao tác: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập tên khách hàng: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Nhập tuổi: ");
                scanf("%d", &age);
                if (age >= 60) {
                    enqueue(&queueOld, name, age);
                    printf("→ Đã thêm vào queue người già.\n");
                } else {
                    enqueue(&queueNormal, name, age);
                    printf("→ Đã thêm vào queue thường.\n");
                }
                break;
            case 2:
                if (!isEmpty(&queueOld)) {
                    serve(&queueOld);
                } else if (!isEmpty(&queueNormal)) {
                    serve(&queueNormal);
                } else {
                    printf("Không có khách nào để phục vụ.\n");
                }
                break;
            case 3:
                displayQueue(&queueOld, "Hàng đợi người già (>=60)");
                displayQueue(&queueNormal, "Hàng đợi thường (<60)");
                break;
            case 4:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 4);

    return 0;
}
