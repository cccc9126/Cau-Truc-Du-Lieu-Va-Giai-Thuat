//
// Created by Cachiu on 30/6/25.
//
#include <stdio.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[1000];

    printf("Nhập chuỗi ký tự bất kỳ: ");
    fgets(str, sizeof(str), stdin);

    // Xóa ký tự newline nếu có
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    printf("\nChuỗi trước khi sắp xếp:\n%s\n", str);

    sortString(str);

    printf("\nChuỗi sau khi sắp xếp theo thứ tự a → z:\n%s\n", str);

    return 0;
}
