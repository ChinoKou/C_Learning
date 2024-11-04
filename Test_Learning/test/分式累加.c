#include <stdio.h>

int main () {
    int n;
    double result = 1, a1 = 1, b1 = 2, c1, a0 = 1, b0 = 1, c0;
    scanf("%d", &n);
    if (n >= 2) {
        result -= 0.5;
        for (int i = 3; i <= n; i++) {
            c1 = a1 + b1;
            c0 = a0 + b0;
            if (i % 2 == 0) {
                result -= (c0) / (c1);
            }
            else if (i % 2 != 0) {
                result += (c0) / (c1);
            }
            a1 = b1;
            b1 = c1;
            a0 = b0;
            b0 = c0;
        }
    }
    printf("%lf", result);
    return 0;
}