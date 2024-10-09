#include <stdio.h>

int main () {
    int n;
    double output = 1, j = 3;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            output -= 1 / j;
        }
        if (i % 2 != 0) {
            output += 1 / j;
        }
        j += 2;
    }
    printf("%.2lf", output);
    return 0;
}