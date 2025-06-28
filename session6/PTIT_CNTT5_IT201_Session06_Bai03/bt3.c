//
// Created by Cachiu on 27/6/25.
//
#include <stdio.h>
#include <math.h>
int sumInNumber(int n,int length,int sum) {

    if (length==0) {
        return sum;
    }
    int temp=n;
    temp/=(pow(10,length-1));

    n=n-temp*(pow(10,length-1));
    sum+=temp;
   return sumInNumber(n,length-1,sum);

}
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int temp=n;
    int length=1;
    while (temp>=10) {
        length++;
        temp/=10;
    }
    int sum=0;
    sumInNumber(n,length,sum);
    printf("%d",sumInNumber(n,length,sum));
}