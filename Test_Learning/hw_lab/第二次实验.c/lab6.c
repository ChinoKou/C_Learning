#include <stdio.h>

int is_sxh (int i, int arr[5]);

void main () {
    int len, temp, arr[5] = {0, 0, 0, 0, 0}, count = 0;
    for (int i = 1; i <= 10000; i++) {
        temp = i;
        for (int j = 0; temp >= 1; j++) {
            arr[j] = temp % 10;
            temp /= 10;
        }
        if (is_sxh(i, arr) == 1) {
            printf("%d\n", i);
            count += 1;
        }
    }
    printf("一共有 %d 个", count);
}

int is_sxh (int i, int arr[5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i] * arr[i] * arr[i];
    }
    if (sum == i) {
        return 1;
    }
    return 0;
}