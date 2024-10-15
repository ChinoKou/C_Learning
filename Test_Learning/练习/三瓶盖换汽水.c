#include <stdio.h>

void main () {
    int n, used, still, count = 0;
    scanf("%d", &n);
    still = n;
    while (still != 2) {
        used = still / 3;
        still = n % 3 + used;
        count += used;
    }
    count += 1;
    printf("%d", count);
}