//
// Created by Cachiu on 16/7/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syslimits.h>
#define MAXNAME 100
#define MAX 100

typedef struct Trip {
    int id;
    char destination[MAXNAME];
    char startDate[20];
    int duration;
} Trip;

typedef struct NodeA {
    Trip trip;
    struct NodeA *next;
} NodeA;

typedef struct NodeB {
    Trip trip;
    struct NodeB *next;
    struct NodeB *prev;
} NodeB;

NodeA *addTrip(NodeA *headA,int* idA) {
    int id;
    char destination[MAXNAME];
    char startDate[20];
    int duration;
    while (getchar() != '\n');
    printf("Enter destination: ");
    fgets(destination, MAXNAME, stdin);
    destination[strcspn(destination, "\n")] = '\0';
    printf("Enter start date: ");
    fgets(startDate, 20, stdin);
    startDate[strcspn(startDate, "\n")] = '\0';
    printf("Enter duration: ");
    scanf("%d", &duration);
    getchar();
    NodeA *newNode =(NodeA*)malloc(sizeof(NodeA));
    newNode->trip.id=++*idA;
    strcpy(newNode->trip.destination, destination);
    strcpy(newNode->trip.startDate, startDate);
    newNode->trip.duration=duration;
   if (headA==NULL) {
       headA=newNode;
       newNode->next=NULL;
   }else {
       NodeA *current=headA;
        while (current->next!=NULL) {
            current=current->next;
        }
       current->next=newNode;
       newNode->next=NULL;
   }
    printf("Đã thêm thành công chuyến đi.\n");
    int out;
    while (out!=0) {
        printf("Enter 0 to exit: ");
        scanf("%d", &out);
        if (out==0) break;
    }
    return headA;
}
void displayTrip(NodeA *headA) {
    if (headA==NULL) {
        printf("Chưa có chuyến đi nào.\n");
        return;
    }
    NodeA*current=headA;
    printf("==================================================================\n");
    while (current!=NULL) {
        printf("ID: %d | DESTINATION: %s | START DATE: %s | DURATION: %d\n",current->trip.id,current->trip.destination,current->trip.startDate,current->trip.duration);
        current=current->next;
    }
    printf("==================================================================\n");
    int out;
    while (out!=0) {
        printf("Enter 0 to exit: ");
        scanf("%d", &out);
        if (out==0) break;
    }
}
NodeA* deleteTrip(NodeA* headA, int idA) {
    int dltId;
    if (headA==NULL) {
        printf("Chưa có chuyến đi nào.\n");
        return headA;
    }
    do {
        printf("Nhập ID bạn muốn xóa: ");
        scanf("%d", &dltId);
        getchar();
        if (dltId<0||dltId>idA) {
            printf("ID không hợp lệ vui lòng nhập lại.");
        }
    }while (dltId<0||dltId>idA);
    NodeA* current = headA;
    NodeA* pre = NULL;
    while (current != NULL) {
        if (current->trip.id == dltId) {
            if (pre == NULL) {
                headA = current->next;
            } else {
                pre->next = current->next;
            }
            free(current);
            printf("Đã xóa thành công chuyến đi có ID %d.\n", dltId);
            return headA;
        }
        pre = current;
        current = current->next;
    }
    printf("Không tìm thấy chuyến đi với ID %d.\n", dltId);
    return headA;
}
NodeA* updateTrip(NodeA*headA,int idA) {
    if (headA==NULL) {
        printf("Chưa có chuyến đi nào.\n");
        return headA;
    }
    int updateId;
    do {
        printf("Nhập ID bạn muốn chỉnh sửa: ");
        scanf("%d", &updateId);
        getchar();
        if (updateId<0||updateId>idA) {
            printf("ID không hợp lệ vui lòng nhập lại.");
        }
    }while (updateId<0||updateId>idA);
    NodeA* current = headA;
    while (current->trip.id != updateId) {
        current = current->next;
    }
    printf("ID: %d| DESTINATION: %s\nSTART DATE: %s|DURATION: %d",current->trip.id,current->trip.destination,current->trip.startDate,current->trip.duration);
    char updateDestination[MAXNAME];
    char updateStartDate[20];
    int duration;
    printf("Hãy nhập điểm đến mới:");
    fgets(updateDestination, MAXNAME, stdin);
    updateDestination[strcspn(updateDestination, "\n")] = '\0';
    printf("Hãy nhập ngày khởi hành mới: ");
    fgets(updateStartDate,20,stdin);
    updateStartDate[strcspn(updateStartDate, "\n")] = '\0';
    printf("Hãy nhập thời lượng chuyến đi mới: ");
    scanf("%d", &duration);
    getchar();

    strcpy(current->trip.destination, updateDestination);
    strcpy(current->trip.startDate, updateStartDate);
    current->trip.duration=duration;
    return headA;
}
NodeA* completeTrip(NodeA*headA,int idA,NodeB*headB) {
    if (headA==NULL) {
        printf("Chưa có chuyến đi nào.\n");
        return headA;
    }
    int comId;

    do {
        printf("Nhập ID bạn muốn chỉnh sửa: ");
        scanf("%d", &comId);
        getchar();
        if (comId<0||comId>idA) {
            printf("ID không hợp lệ vui lòng nhập lại.");
        }
    }while (comId<0||comId>idA);
    NodeA*current=headA;
    NodeA*pre=NULL;
    while (current->trip.id!=comId) {
        current=current->next;
    }
    NodeB*newNode=(NodeB*)malloc(sizeof(NodeB));
    newNode->trip=current->trip;
    newNode->next=NULL;
    newNode->prev=NULL;
    if (pre == NULL) {
        headA = current->next;
    } else {
        pre->next = current->next;
    }
    free(current);
    if (headB==NULL) {
        headB=newNode;
    }
    else {
        NodeB*current=headB;
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=newNode;
        newNode->next=NULL;
        newNode->prev=current;
    }
    printf("Đánh dấu thành công.\n");
    return headA;

}
NodeA* sortTrip(NodeA* headA) {
    if (headA == NULL || headA->next == NULL) return headA;
    NodeA* ptr;
    NodeA* lptr = NULL;
    int swapped;
    do {
        swapped = 0;
        ptr = headA;
        while (ptr->next != lptr) {
            if (strcmp(ptr->trip.startDate, ptr->next->trip.startDate) > 0) {
                Trip temp = ptr->trip;
                ptr->trip = ptr->next->trip;
                ptr->next->trip = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);

    printf("Đã sắp xếp chuyến đi theo ngày khởi hành.\n");
    return headA;
}

NodeA* searchTrip(NodeA* headA) {
    if (headA == NULL) {
        printf("Danh sách chuyến đi trống.\n");
        return headA;
    }

    while (getchar() != '\n');

    char destination[MAXNAME];
    printf("Nhập điểm đến bạn muốn tìm kiếm: ");
    fgets(destination, MAXNAME, stdin);
    destination[strcspn(destination, "\n")] = '\0';

    int found = 0;
    NodeA* current = headA;
    while (current != NULL) {
        if (strstr(current->trip.destination, destination) != NULL) {
            printf("ID: %d | DESTINATION: %s | START DATE: %s | DURATION: %d\n",
                current->trip.id,
                current->trip.destination,
                current->trip.startDate,
                current->trip.duration);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Không tìm thấy chuyến đi nào với điểm đến \"%s\".\n", destination);
    }

    return headA;
}

int main() {
    int idA=-1;
    NodeA *headA = NULL;
    NodeB *headB = NULL;
    int choice;
    do {
        printf("========MENU=======\n");
        printf("1. Thêm chuyến đi.\n");
        printf("2. Hiển thị danh sách chuyến đi.\n");
        printf("3. Xóa chuyến đi.\n");
        printf("4. Cập nhật thông tin chuyến đi.\n");
        printf("5. Đánh dấu chuyến đi đã hoàn thành\n");
        printf("6. Sắp xếp chuyến đi theo ngày khởi hành.\n");
        printf("7. Tìm kiếm chuyến đi theo điểm đến.\n");
        printf("8. Thoát chương trình\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                headA = addTrip(headA,&idA);
                break;
            case 2:
                displayTrip(headA);
                break;
            case 3:
                headA=deleteTrip(headA,idA);
                break;
            case 4:
                headA=updateTrip(headA,idA);
                break;
            case 5:
                headA=completeTrip(headA,idA,headB);
                break;
            case 6:
                headA=sortTrip(headA);
                break;
            case 7:
                searchTrip(headA);
                break;
            case 8:
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại\n");
        }
    } while (choice != 8);
    return 0;
}
