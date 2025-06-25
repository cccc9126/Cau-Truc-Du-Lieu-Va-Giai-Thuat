#include <stdio.h>

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
     fflush(stdin);
     printf("Nhap name[%d]:",i);
     scanf("%s",arr[i].name);
     printf("Nhap age[%d]:",i);
     scanf("%d",&arr[i].age);
     if (arr[i].id<=0||arr[i].age<=0) {}
   };


  int number;
  printf("Enter number:");
  scanf("%d",&number);
  if (number>5||number<=0) {
    printf("Invalid input\n");
    return 0;
  }
  for (int i=0;i<5;i++) {
    if (arr[i].id==number) {
      printf("ID: %d\n",arr[i].id);
      printf("Name: %s\n",arr[i].name);
      printf("Age: %d\n",arr[i].age);
    }
  }

  return 0;
}
