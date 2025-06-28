#include <stdio.h>


void towerOfHanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Di chuyen dia 1 tu %c sang %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, to, aux);
    printf("Di chuyen dia %d tu %c sang %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, from, to);
}
int main() {
    int n = 3;
    printf("Cac buoc di chuyen %d dia:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
