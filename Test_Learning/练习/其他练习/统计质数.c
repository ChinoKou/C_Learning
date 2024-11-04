#include <stdio.h>

int main () {
    int n, count, output = 0;
    printf("请输入一个整数：\n");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            if (n % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0) {
            output++;
        }
    }
    printf("有 %d 个质数", output);
    return 0;
}