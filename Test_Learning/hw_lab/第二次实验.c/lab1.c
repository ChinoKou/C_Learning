#include <stdio.h>


void main () {
    double x, result;
    scanf("%lf", &x);
    if (x <= 30000) {
        result = 0;
    }
    else if (x > 30000 && x <= 50000) {
        result = (x - 30000) * 0.03;
    }
    else if (x > 50000 && x <= 100000) {
        result = 20000 * 0.03 + (x - 50000) * 0.06;
    }
    else if (x > 100000) {
        result = 20000 * 0.03 + 50000 * 0.06 + (x - 100000) * 0.1;
    }
    printf("%.2lf", result);
}