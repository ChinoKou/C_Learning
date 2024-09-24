#include <stdio.h>

int main () {
    int a, b, count = 0;
    scanf("%d %d", &a, &b);
    int min = a > b ? b : a;
    int max = a > b ? a : b;
    for (int i = min; i <= max; i++) {
        if (i % 6 == 0 && i % 8 == 0) {
            count += 1;
            printf("%d ", i);
        }
    }
    printf("%d", count);
}