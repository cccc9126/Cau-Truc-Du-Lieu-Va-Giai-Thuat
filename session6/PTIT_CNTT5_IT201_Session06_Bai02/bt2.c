//
// Created by Cachiu on 27/6/25.
//
#include <stdio.h>
void fibonacci(int n,int first, int second,int arr[],int temp) {
    if (n<2||temp>n) {
        return;
    }else {
        arr[temp]=first+second;
        fibonacci(n,second,first+second,arr,temp+1);
    }

}
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int first=0;
    int second=1;
    int arr[n];
    arr[0]=first;
    arr[1]=second;
    int temp=2;
    fibonacci(n,first,second,arr,temp);
    for (int i = n; i >0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}