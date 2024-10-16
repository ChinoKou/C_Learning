#include <stdio.h>

int main () {
    double x, y;
    printf("请输入工资 x 的值: ");
    scanf("%lf", &x);
    if (x <= 30000) {
        y = 0;
    }
    else if (x > 30000 && x <= 50000) {
        y = (x - 30000) * 0.03;
    }
    else if (x > 50000 && x <= 100000) {
        y = 20000 * 0.03 + (x - 50000) * 0.06;
    }
    else if (x > 100000) {
        y = 20000 * 0.03 + 50000 * 0.06 + (x - 100000) * 0.1;
    }
    printf("%.2lf", y);
    return 0;
}