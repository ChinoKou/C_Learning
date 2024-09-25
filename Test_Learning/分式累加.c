#include <stdio.h>

int main () {
    int n;
    double result = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        double j = i;
        if (i % 2 == 0) {
            result -= (j - 1) / (j);
        }
        else if (i % 2 != 0) {
            result += (j - 1) / (j);
        }
    }
    printf("%lf", result);
    return 0;
}