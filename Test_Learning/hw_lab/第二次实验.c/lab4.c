#include <stdio.h>
#include <math.h>

void main () {
    int x, i = 0, num_len; 
    scanf("%d", &x);
    num_len = floor(log10(x)) + 1;
    int arr[num_len];
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
}