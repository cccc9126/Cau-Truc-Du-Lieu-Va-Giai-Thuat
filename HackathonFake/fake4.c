//
// Created by Cachiu on 15/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAXNAME 100

// ======== STRUCT DEFINITION =========
typedef struct {
    char songName[MAXNAME];
} Song;

typedef struct {
    Song data[MAX];
    int front, rear;
} Queue;

typedef struct {
    Song data[MAX];
    int top;
} Stack;

// ======== QUEUE FUNCTIONS =========
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->rear < q->front;
}

int isQueueFull(Queue *q) {
    return q->rear - q->front + 1 == MAX;
}

void enqueue(Queue *q, Song s) {
    if (isQueueFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = s;
}

Song dequeue(Queue *q) {
    Song empty = {"<empty>"};
    if (isQueueEmpty(q)) {
        printf("No songs in queue.\n");
        return empty;
    }
    return q->data[q->front++];
}

// ======== STACK FUNCTIONS =========
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, Song song) {
    if (isStackFull(s)) {
        printf("History is full!\n");
        return;
    }
    s->data[++(s->top)] = song;
}

Song pop(Stack *s) {
    Song empty = {"<empty>"};
    if (isStackEmpty(s)) {
        printf("No previous song.\n");
        return empty;
    }
    return s->data[(s->top)--];
}

void showHistory(Stack s) {
    if (isStackEmpty(&s)) {
        printf("No songs played yet.\n");
        return;
    }
    printf("\n--- HISTORY ---\n");
    for (int i = s.top; i >= 0; i--) {
        printf("%s\n", s.data[i].songName);
    }
    printf("----------------\n");
}

int main() {
    Queue nextQueue;
    Stack historyStack;

    initQueue(&nextQueue);
    initStack(&historyStack);

    int choice;
    Song currentSong;
    Song tempSong;

    do {
        printf("\n——————————— MUSIC PLAYER ———————————\n");
        printf("1. ADD: Thêm bài hát vào hàng đợi phát (queue)\n");
        printf("2. PLAY NEXT: Phát bài tiếp theo từ queue → lưu vào stack\n");
        printf("3. PLAY PREVIOUS: Quay lại bài trước (hiện tên bài trước trong stack)\n");
        printf("4. HISTORY: Hiển thị lịch sử các bài hát đã phát\n");
        printf("5. EXIT: Thoát chương trình\n");
        printf("Chọn thao tác (1-5): ");
        scanf("%d", &choice);
        getchar(); // Đọc ký tự '\n'

        switch (choice) {
            case 1:
                printf("Nhập tên bài hát: ");
                fgets(tempSong.songName, MAXNAME, stdin);
                tempSong.songName[strcspn(tempSong.songName, "\n")] = 0; // remove newline
                enqueue(&nextQueue, tempSong);
                printf(">> Đã thêm \"%s\" vào danh sách phát\n", tempSong.songName);
                break;

            case 2:
                if (!isQueueEmpty(&nextQueue)) {
                    currentSong = dequeue(&nextQueue);
                    push(&historyStack, currentSong);
                    printf(">> Đang phát: %s\n", currentSong.songName);
                } else {
                    printf(">> Không có bài hát nào trong danh sách phát\n");
                }
                break;

            case 3:
                if (!isStackEmpty(&historyStack)) {
                    currentSong = pop(&historyStack);
                    printf(">> Quay lại phát: %s\n", currentSong.songName);
                } else {
                    printf(">> Không có bài hát trước đó để quay lại\n");
                }
                break;

            case 4:
                showHistory(historyStack);
                break;

            case 5:
                printf(">> Thoát chương trình...\n");
                break;

            default:
                printf(">> Lựa chọn không hợp lệ! Vui lòng chọn 1 - 5.\n");
        }

    } while (choice != 5);

    return 0;
}
