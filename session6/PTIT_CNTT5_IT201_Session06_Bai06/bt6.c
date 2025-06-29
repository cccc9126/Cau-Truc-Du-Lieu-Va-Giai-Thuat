#include <stdio.h>

int countWays(int n) {
    printf("Goi countWays(%d)\n", n);
    if (n == 0) return 1;
    if (n < 0)  return 0;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;

    printf("Nhap so bac cua cau thang: ");
    scanf("%d", &n);

    int ways = countWays(n);
    printf("So cach leo cau thang co %d bac la: %d\n", n, ways);

    return 0;
}
