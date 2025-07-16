#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAXNAME 100

// ======= Cấu trúc bài hát ========
typedef struct {
    char songName[MAXNAME];
} Song;

// ======= Hàng đợi phát nhạc (Queue) ========
typedef struct {
    Song songs[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front > q->rear;
}

int isQueueFull(Queue* q) {
    return q->rear >= MAX - 1;
}

void enqueue(Queue* q, Song s) {
    if (isQueueFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->songs[++q->rear] = s;
}

Song dequeue(Queue* q) {
    Song temp;
    strcpy(temp.songName, "");
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return temp;
    }
    return q->songs[q->front++];
}

// ======= Ngăn xếp lịch sử phát nhạc (Stack) ========
typedef struct {
    Song songs[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

int isStackFull(Stack* s) {
    return s->top >= MAX - 1;
}

void push(Stack* s, Song song) {
    if (isStackFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->songs[++s->top] = song;
}

Song pop(Stack* s) {
    Song temp;
    strcpy(temp.songName, "");
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return temp;
    }
    return s->songs[s->top--];
}

Song peek(Stack* s) {
    Song temp;
    strcpy(temp.songName, "");
    if (!isStackEmpty(s)) {
        return s->songs[s->top];
    }
    return temp;
}

// ======= Thêm bài hát vào queue ========
void addSong(Queue* q) {
    if (isQueueFull(q)) {
        printf("Playlist is full.\n");
        return;
    }
    while (getchar() != '\n'); // clear buffer
    char name[MAXNAME];
    printf("Enter song name: ");
    fgets(name, MAXNAME, stdin);
    name[strcspn(name, "\n")] = '\0'; // xóa dấu '\n'
    Song s;
    strcpy(s.songName, name);
    enqueue(q, s);
    printf("Added: %s\n", s.songName);
}

// ======= Phát bài tiếp theo ========
void playNext(Queue* q, Stack* history, Stack* redo) {
    // Ưu tiên lấy lại từ redo nếu vừa PREVIOUS
    if (!isStackEmpty(redo)) {
        Song s = pop(redo);
        push(history, s);
        printf("Now playing (from redo): %s\n", s.songName);
    } else if (!isQueueEmpty(q)) {
        Song s = dequeue(q);
        push(history, s);
        printf("Now playing: %s\n", s.songName);
    } else {
        printf("No songs to play.\n");
    }
}

// ======= Quay lại bài trước đó ========
void playPrevious(Stack* history, Stack* redo) {
    if (history->top <= 0) {
        printf("No previous song.\n");
    } else {
        Song current = pop(history);  // Lấy bài hiện tại ra
        push(redo, current);          // Lưu vào redo để có thể phát lại
        Song previous = peek(history); // Lấy bài trước đó
        printf("Now playing previous: %s\n", previous.songName);
    }
}

// ======= Hiển thị lịch sử các bài đã phát ========
void showHistory(Stack* history) {
    if (isStackEmpty(history)) {
        printf("No songs have been played.\n");
    } else {
        printf("History of played songs:\n");
        for (int i = 0; i <= history->top; i++) {
            printf("- %s\n", history->songs[i].songName);
        }
    }
}

// ======= Main Program ========
int main() {
    Queue playlist;
    Stack history, redo;

    initQueue(&playlist);
    initStack(&history);
    initStack(&redo);

    int choice;
    do {
        printf("\n——— MUSIC PLAYER ———\n");
        printf("1. ADD\n");
        printf("2. PLAY NEXT\n");
        printf("3. PLAY PREVIOUS\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(&playlist);
                break;
            case 2:
                playNext(&playlist, &history, &redo);
                break;
            case 3:
                playPrevious(&history, &redo);
                break;
            case 4:
                showHistory(&history);
                break;
            case 5:
                printf("Exiting music player.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
