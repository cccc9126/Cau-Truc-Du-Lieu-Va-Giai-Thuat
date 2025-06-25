//
// Created by Cachiu on 25/6/25.
//
#include <stdio.h>
#include <string.h>

struct Person {
    int id;
    char name[20];
    int age;
};

int main() {
    struct Person arr[5];
    for (int i=0;i<5;i++) {
        printf("Nhap id[%d]:",i);
        scanf("%d",&arr[i].id);
        getchar();
        printf("Nhap name[%d]:",i);
        fgets(arr[i].name,20,stdin);
        arr[i].name[strlen(arr[i].name)-1]='\0';
        printf("Nhap age[%d]:",i);
        scanf("%d",&arr[i].age);

    };
getchar();
    char name[20];
    printf("Enter name:");

    fgets(name,20,stdin);
    name[strlen(name)-1]='\0';
    for (int i=0;i<5;i++) {
        if (strstr(arr[i].name,name) != NULL) {
            printf("ID[%d] = %d\n",i,arr[i].id);
            printf("Name[%d] = %s\n",i,arr[i].name);
            printf("Age[%d] = %d\n",i,arr[i].age);
            printf("\n");
        }
        
    }
    return 0;
}
