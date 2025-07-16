//
// Created by Cachiu on 15/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Product {
    int id;
    char name[100];
    float price;
    int quantity;
} Product;

typedef struct Node {
    Product data;
    struct Node* next;
} Node;

typedef struct DNode {
    Product data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

Node* head = NULL;
DNode* soldHead = NULL;
DNode* soldTail = NULL;

int equalIgnoreCase(char *a, char *b) {
    while (*a && *b) {
        if (tolower(*a++) != tolower(*b++)) return 0;
    }
    return *a == *b;
}


void addProduct() {
    Product p;
    printf("ID: "); scanf("%d", &p.id);
    getchar();
    printf("Name: "); fgets(p.name, 100, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';


    Node* curr = head;
    while (curr) {
        if (equalIgnoreCase(curr->data.name, p.name)) {
            printf("Tên sản phẩm bị trùng!\n");
            return;
        }
        curr = curr->next;
    }

    printf("Price: "); scanf("%f", &p.price);
    printf("Quantity: "); scanf("%d", &p.quantity);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = head;
    head = newNode;
}


void displayProducts() {
    Node* curr = head;
    if (!curr) {
        printf("Không có sản phẩm nào.\n");
        return;
    }
    while (curr) {
        printf("ID: %d | Name: %s | Price: %.2f | Qty: %d\n",
                curr->data.id, curr->data.name, curr->data.price, curr->data.quantity);
        curr = curr->next;
    }
}


void deleteProduct(int id) {
    Node *curr = head, *prev = NULL;
    while (curr) {
        if (curr->data.id == id) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            printf("Đã xóa sản phẩm.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Không tìm thấy sản phẩm.\n");
}


void updateProduct(int id) {
    Node* curr = head;
    while (curr) {
        if (curr->data.id == id) {
            char newName[100];
            getchar();
            printf("Tên mới: "); fgets(newName, 100, stdin);
            newName[strcspn(newName, "\n")] = '\0';


            Node* temp = head;
            while (temp) {
                if (temp != curr && equalIgnoreCase(temp->data.name, newName)) {
                    printf("Tên bị trùng!\n");
                    return;
                }
                temp = temp->next;
            }

            strcpy(curr->data.name, newName);
            printf("Giá mới: "); scanf("%f", &curr->data.price);
            printf("Số lượng mới: "); scanf("%d", &curr->data.quantity);
            printf("Đã cập nhật.\n");
            return;
        }
        curr = curr->next;
    }
    printf("Không tìm thấy sản phẩm.\n");
}


void markAsSold(int id) {
    Node *curr = head, *prev = NULL;
    while (curr) {
        if (curr->data.id == id) {

            DNode* soldNode = (DNode*)malloc(sizeof(DNode));
            soldNode->data = curr->data;
            soldNode->next = NULL;
            soldNode->prev = soldTail;
            if (soldTail) soldTail->next = soldNode;
            else soldHead = soldNode;
            soldTail = soldNode;


            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            printf("Đã chuyển sản phẩm sang danh sách đã bán.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Không tìm thấy sản phẩm.\n");
}


void displaySold() {
    DNode* curr = soldHead;
    if (!curr) {
        printf("Không có sản phẩm đã bán.\n");
        return;
    }
    while (curr) {
        printf("ID: %d | Name: %s | Price: %.2f | Qty: %d\n",
                curr->data.id, curr->data.name, curr->data.price, curr->data.quantity);
        curr = curr->next;
    }
}

void sortByPrice() {
    if (!head || !head->next) return;
    int swapped;
    Node *ptr, *lptr = NULL;

    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != lptr) {
            if (ptr->data.price > ptr->next->data.price) {
                Product temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
    printf("Đã sắp xếp theo giá.\n");
}


void searchByName(char* keyword) {
    Node* curr = head;
    int found = 0;
    while (curr) {
        if (strstr(curr->data.name, keyword)) {
            printf("ID: %d | Name: %s | Price: %.2f | Qty: %d\n",
                   curr->data.id, curr->data.name, curr->data.price, curr->data.quantity);
            found = 1;
        }
        curr = curr->next;
    }
    if (!found) printf("Không tìm thấy sản phẩm.\n");
}

// Menu chính
int main() {
    int choice, id;
    char keyword[100];
    do {
        printf("\n=== MENU ===\n");
        printf("1. Thêm sản phẩm\n");
        printf("2. Hiển thị danh sách sản phẩm\n");
        printf("3. Xóa sản phẩm theo ID\n");
        printf("4. Cập nhật thông tin sản phẩm\n");
        printf("5. Đánh dấu sản phẩm đã bán\n");
        printf("6. Hiển thị danh sách đã bán\n");
        printf("7. Sắp xếp theo giá\n");
        printf("8. Tìm kiếm theo tên\n");
        printf("0. Thoát\n");
        printf("Chọn: "); scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: printf("Nhập ID: "); scanf("%d", &id); deleteProduct(id); break;
            case 4: printf("Nhập ID: "); scanf("%d", &id); updateProduct(id); break;
            case 5: printf("Nhập ID: "); scanf("%d", &id); markAsSold(id); break;
            case 6: displaySold(); break;
            case 7: sortByPrice(); break;
            case 8:
                getchar();
                printf("Từ khóa: ");
                fgets(keyword, 100, stdin);
                keyword[strcspn(keyword, "\n")] = '\0';
                searchByName(keyword);
                break;
            case 0: printf("Tạm biệt!\n"); break;
            default: printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 0);
    return 0;
}
