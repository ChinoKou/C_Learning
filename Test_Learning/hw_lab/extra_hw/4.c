#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main () {
    double r = 1.5, h = 3, pi = M_PI, l, s1, s2, v1, v2;
    while (1) {
        l = 2 * pi * r;
        s1 = pi * pow(r, 2);
        s2 = 4 * pi * pow(r, 2);
        v1 = 4 / 3 * pi * pow(r, 3);
        v2 = s1 * h;
        printf("圆周长为：%.2lf, 圆面积为：%.2lf, 球面积为：%.2lf, 球体积为：%.2lf, 圆柱体积为：%.2lf\n", l, s1, s2, v1, v2);
        printf("\n");
        printf("请输入半径和高: (r h)\n");
        scanf("%lf %lf", &r, &h);
    }
    return 0; 
}