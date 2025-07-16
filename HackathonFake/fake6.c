#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100

typedef struct Node {
    char url[MAX_URL];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = stack->top;
    stack->top = newNode;
}

char* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;

    Node* temp = stack->top;
    char* url = (char*)malloc(MAX_URL);
    strcpy(url, temp->url);
    stack->top = temp->next;
    free(temp);
    return url;
}

void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        Node* temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    if (!current) {
        printf("Không có lịch sử truy cập.\n");
        return;
    }
    printf("Lịch sử truy cập (mới nhất → cũ nhất):\n");
    while (current != NULL) {
        printf(" - %s\n", current->url);
        current = current->next;
    }
}

// Hàm chính
int main() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);
    char currentUrl[MAX_URL] = "about:blank";

    int choice;
    char inputUrl[MAX_URL];

    do {
        printf("\n—————— BROWSER HISTORY MANAGER ——————\n");
        printf("Trang hiện tại: %s\n", currentUrl);
        printf("1. VISIT\n2. BACK\n3. FORWARD\n4. HISTORY\n5. THOÁT\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập URL mới: ");
                fgets(inputUrl, MAX_URL, stdin);
                inputUrl[strcspn(inputUrl, "\n")] = 0;

                push(&backStack, currentUrl);
                strcpy(currentUrl, inputUrl);
                clearStack(&forwardStack);
                break;

            case 2:
                if (isEmpty(&backStack)) {
                    printf("Không thể quay lại. Không có lịch sử.\n");
                } else {
                    push(&forwardStack, currentUrl);
                    char* url = pop(&backStack);
                    strcpy(currentUrl, url);
                    free(url);
                }
                break;

            case 3:
                if (isEmpty(&forwardStack)) {
                    printf("Không thể tiến tới. Không có trang nào phía trước.\n");
                } else {
                    push(&backStack, currentUrl);
                    char* url = pop(&forwardStack);
                    strcpy(currentUrl, url);
                    free(url);
                }
                break;

            case 4:
                printStack(&backStack);
                break;

            case 5:
                printf("Đang thoát chương trình...\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }

    } while (choice != 5);

    clearStack(&backStack);
    clearStack(&forwardStack);

    return 0;
}
