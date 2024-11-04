#include <stdio.h>

int main () {
    double a, b, result, min, max;
    scanf("%lf %lf", &a, &b);
    min = a < b ? a : b;
    max = a > b ? a : b;
    for (double i = min; i <= max; i++) {
        result = 5.0 / 9 * (i - 32);
        printf("F: %lf ℃: %lf \t\n", i, result);
    }
    return 0;
}