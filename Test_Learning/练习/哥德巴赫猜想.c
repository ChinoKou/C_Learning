//输入一个偶数 N，验证 4∼N 所有偶数是否符合哥德巴赫猜想：任一大于 2 的偶数都可写成两个质数之和。
//如果一个数不止一种分法，则输出第一个加数相比其他分法最小的方案。
//例如 10，10=3+7=5+5，则 10=5+5 是错误答案。

#include <stdio.h>

int is_prime (int a);

int main () {
    int N, x, y;
    scanf("%d", &N);
    for (int i = 4; i <= N; i += 2) {
        for (x = 2; x <= i / 2; x++) {
            y = i - x;
            if (is_prime(x) + is_prime(y) == 0) {
                printf("%d=%d+%d\n", i, x, y);
                break;
            }
        }
    }
    return 0;
}

int is_prime (int a) {
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            return 1;
        }
    }
    return 0;
}