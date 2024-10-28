#include <stdio.h>

long long fun (int n);

int main () {
    int n;
    printf("求 1 * 3 * 5 * 7 * ... * (2n - 1) 的值\n");
    printf("请输入 n 的值: ");
    scanf("%d", &n);
    printf("1 * 3 * ... * %d 的值: %lld", 2 * n - 1, fun(n));
    return 0;
}

long long fun (int n) {
    long long sum = 1;
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        sum *= i;
    }
    return sum;
}