#include <stdio.h>
#include <math.h>

int main () {
    double x, output;
    scanf("%lf", &x);
    if (x < 0) {
        output = pow(x, 5) + x * 2 + 1 / x;
    }
    else if (x >= 0) {
        output = pow(x, 0.5);
    }
    printf("x = %.2lf, y = %.2lf", x, output);
    return 0;
}