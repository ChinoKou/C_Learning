#include <stdio.h>
#include <math.h>

int main () {
    int a, a0, b, x;
    scanf("%d %d %d", &a, &b, &x);
    a0 = a;
    int y = pow(10, x);
    for (int i = 1; i < b; i++) {
        a0 = a0 * a % y;
    }
    printf("%d", a0);
    return 0;
}