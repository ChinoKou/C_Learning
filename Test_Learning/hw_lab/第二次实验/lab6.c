#include <stdio.h>

int main () {
    int sum, digit, count = 0;
    printf("1 - 10000 间的所有水仙花数: \n");
    for (int i = 1; i <= 10000; i++) {
        sum = 0;
        for (int j = i; j >= 1; j /= 10) {
            digit = j % 10;
            sum += digit * digit * digit;
        }
        if (sum == i) {
            printf("%d\n", i);
            count += 1;
        }
    }
    printf("一共有 %d 个", count);
    return 0;
}