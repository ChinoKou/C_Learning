#include <stdio.h>

int main () {
    int len, temp, sum, arr[5] = {0, 0, 0, 0, 0}, count = 0;
    printf("1 - 10000 间的所有水仙花数: \n");
    for (int i = 1; i <= 10000; i++) {
        temp = i;
        sum = 0;
        for (int j = 0; temp >= 1; j++) {
            arr[j] = temp % 10;
            temp /= 10;
            sum += arr[j] * arr[j] * arr[j];
        }
        if (sum == i) {
            printf("%d\n", i);
            count += 1;
        }
    }
    printf("一共有 %d 个", count);
    return 0;
}