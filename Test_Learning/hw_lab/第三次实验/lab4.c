#include <stdio.h>

int fact (int n);

int main () {
    int n;
    printf("请输入 n 的值: ");
    scanf("%d", &n);
    printf("t = %d! 的值: %d", n, fact(n));
    return 0;
}

int fact (int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++) {
        sum *= i;
    }
    return sum;
}