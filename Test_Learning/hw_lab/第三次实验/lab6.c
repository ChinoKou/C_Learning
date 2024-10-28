#include <stdio.h>

double fun (int n, double x);

int main () {
    int n;
    double x;
    printf("求 n 阶勒让德多项式的值\n");
    printf("请输入一个整数 n (n >= 0): ");
    scanf("%d", &n);
    printf("请输入一个实数 x : ");
    scanf("%lf", &x);
    printf("%d 阶勒让德多项式的值: %.1lf", n, fun(n, x));
    return 0;
}

double fun (int n, double x) {
    double result_1 = 1, result_2 = x, temp;
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    for (int i = 2; i <= n; i++) {
        temp = result_1;
        result_1 = ((2 * n - 1) * x - result_2 - (n - 1) * result_1) / n;
        result_2 = temp;
    }
    return result_1;
}