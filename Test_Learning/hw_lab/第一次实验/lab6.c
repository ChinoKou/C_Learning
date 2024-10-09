#include <stdio.h>
#include <math.h>

int main () {
    int n;
    double x, output = 0;
    printf("请输入正整数 n 和实数 x :\n");
    scanf("%d %lf", &n, &x);
    for (int i = 1; i <= n; i++) {
        output += pow(x, i);
    }
    printf("S = %.2lf", output);
    return 0;
}