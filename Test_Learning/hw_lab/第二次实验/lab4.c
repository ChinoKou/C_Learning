#include <stdio.h>
#include <math.h>

int main () {
    int x, num_len, i = 0, arr[100]; 
    printf("请输入一个正整数: ");
    scanf("%d", &x);
    num_len = log10(x) + 1;
    printf("%d 从高位开始逐渐分离并输出的结果是", x);
    while (x >= 1) {
        arr[i] = x % 10;
        x /= 10;
        i += 1;
    }
    while (num_len > 0) {
        printf("%d,", arr[num_len - 1]);
        num_len -= 1;
    }
    return 0;
}