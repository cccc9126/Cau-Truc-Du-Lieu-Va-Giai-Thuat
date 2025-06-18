//
// Created by Cachiu on 16/6/25.
//
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 5, 4, 5, 5, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxCount = 0;
    int max;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            max = arr[i];
        }
    }

    printf("Phần tử xuất hiện nhiều nhất là: %d (xuất hiện %d lần)\n", max, maxCount);

    return 0;
}

/*
 * time complexity: O(n^2)
 * space complexity:O(1)
 */
