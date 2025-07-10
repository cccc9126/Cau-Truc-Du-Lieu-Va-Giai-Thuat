#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 31

typedef struct {
    char name[NAME_LEN];
} Customer;

typedef struct {
    Customer queue[MAX];
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


void enqueue(Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Hàng đợi đã đầy. Không thể thêm khách mới.\n");
    } else {
        q->rear++;
        strncpy(q->queue[q->rear].name, name, NAME_LEN - 1);
        q->queue[q->rear].name[NAME_LEN - 1] = '\0';
        printf("Đã thêm khách: %s\n", name);
    }
}


void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng. Không có khách để phục vụ.\n");
    } else {
        printf("Phục vụ khách: %s\n", q->queue[q->front].name);
        q->front++;
    }
}

// Hiển thị danh sách khách đang chờ
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi hiện đang trống.\n");
    } else {
        printf("Danh sách khách đang chờ:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("  - %s\n", q->queue[i].name);
        }
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice;
    char name[NAME_LEN];

    do {
        printf("\n===== QUẦY BÁN VÉ =====\n");
        printf("1. Thêm khách hàng\n");
        printf("2. Phục vụ khách hàng\n");
        printf("3. Hiển thị danh sách chờ\n");
        printf("4. Thoát\n");
        printf("Chọn thao tác: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập tên khách hàng: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                enqueue(&q, name);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Đã thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 4);

    return 0;
}
