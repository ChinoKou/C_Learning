#include <stdio.h>

int factorsum (int x);

int main () {
    int m, n;
    printf("输入两个正整数 m 和 n (1 <= m <= n <= 10000): ");
    scanf("%d %d", &m, &n);
    printf("%d 到 %d 之间的所有完数是: \n", m, n);
    for (int i = m; i <= n; i++) {
        if (i == factorsum(i)) {
            printf("%d  ", i);
        }
    }
    return 0;
}

int factorsum (int x) {
    int sum = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum;
}