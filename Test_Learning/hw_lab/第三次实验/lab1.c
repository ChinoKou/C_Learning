#include <stdio.h>

int fib (int i);

int main () {
    int n, m, arr[10000];
    printf("输入两个正整数m和n (1 <= m <= n <= 10000): ");
    scanf("%d %d", &m, &n);
    printf("第 %d 项到第 %d 项的Fibonacci数是: \n", m, n);
    for (int i = m; i <= n; i++) {
        arr[i - 1] = fib(i);
    }
    for (int i = m; i <= n; i++) {
        printf("%d ", arr[i - 1]);
    }
    return 0;
}

int fib (int i) {
    int a = 1, b= 1, temp;
    for (int h = 3; h <= i; h++) {
        temp = a;
        a += b;
        b = temp;
    }
    return a;
}