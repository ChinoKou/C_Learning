#include <stdio.h>

int main () {
    int num, count;
    printf("请输入一个整数：");
    scanf("%d", &num);
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            count ++;
        }
    }
    if (count == 0) {
        printf("%d 是质数", num);
    } else if (count > 0) {
        printf("%d 不是质数", num);
    }
    return 0;
}