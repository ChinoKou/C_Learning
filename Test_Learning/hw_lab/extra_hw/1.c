#include <stdio.h>
#include <math.h>

int main () {
    int n = 10;
    double r = 0.07, p;
    p = pow((1 + r), n);
    printf("10 年后我国国民生产总值与现在相比增长了 %.2lf%%", p * 100 - 100);
    return 0;
}