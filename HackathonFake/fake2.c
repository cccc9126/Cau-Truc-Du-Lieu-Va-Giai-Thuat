//
// Created by Cachiu on 14/7/25.
//
#include<stdio.h>
#include<string.h>
#define MAXNAME 100
#define MAX 100
typedef struct {
    char songName[MAXNAME];
}Song;
typedef struct{
    Song songs[MAX];
    int front;
    int rear;
}Queue;
typedef struct {
    Song songs[MAX];
    int top;
}Stack;
void innitStack(Stack* s) {
    s->top=-1;
    printf("Khoi tao thanh cong\n");
}
void innitQueue(Queue* q) {
    q->front=0;
    q->rear=-1;
    printf("Khoi tao thanh cong\n");
}
int queueIsEmpty(Queue* q) {
    return q->front>q->rear;
}
int queueIsFull(Queue* q) {
    return q->rear>MAX-1;
}
int stackIsEmpty(Stack*s) {
    return s->top==-1;
}
int stackIsFull(Stack* s) {
    return s->top>MAX-1;
}
void addSong(Queue* q) {
    if (queueIsFull(q)) {
        printf("Playlist is full\n");
    }else{
        while (getchar()!='\n');
        char songName[MAXNAME];
        printf("Enter song name:");
        fgets(songName,MAXNAME,stdin);
        songName[strcspn(songName, "\n")] = '\0';
        strcpy(q->songs[++q->rear].songName,songName);
        printf("Song %s has been added\n",songName);
    }
}
void playNext(Queue* q,Stack *s) {
    if (queueIsEmpty(q)) {
        printf("Playlist is empty\n");
    }else {
        if (stackIsFull(s)) {
            printf("Stack is full\n");
        }else {
            printf("Playing: %s\n",q->songs[q->front++].songName);
            if (q->front-1>0) {
                s->top++;
                strcpy(s->songs[s->top].songName,q->songs[q->front-2].songName);
            }



        }
    }
}
void playPrevious(Stack *s,Queue *q) {
    if (stackIsEmpty(s)) {
        printf("Stack is empty\n");
    }else {
        printf("Playing: %s\n",s->songs[s->top--].songName);
    }
}

int main() {
    Stack s;
    Queue q;
    innitStack(&s);
    innitQueue(&q);


    int choice;
    do {
        printf("======MENU=======\n");
        printf("1. ADD\n");
        printf("2. PLAY NEXT\n");
        printf("3. PLAY PREVIOUS\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("=================\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                addSong(&q);
                break;
            case 2:
                playNext(&q,&s);
                break;
            case 3:
                playPrevious(&s,&q);
                break;

        }
    }while (choice!=5);


}