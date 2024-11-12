#include <stdio.h>

int main () {
    double r, h, C1, Sa, Sb, Va, Vb, PI = 3.14;
    scanf("%lf %lf", &r, &h);
    C1 = 2 * PI * r;
    Sa = PI * r * r;
    Sb = 4 * PI * r * r;
    Va = PI * r * r * r * 4 / 3;
    Vb = Sa * h;
    printf("C1=%.2lf\nSa=%.2lf\nSb=%.2lf\nVa=%.2lf\nVb=%.2lf\n\n", C1, Sa, Sb, Va, Vb);
    return 0;
}