#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x, y, n, count = 0;
    scanf("%d", &n);
    for (y = 1; y <= n; y++) {
        x = n - y;
        if (x >= 1 && (x & y) == 0) {
            count += 1;
        }
    }
    printf("%d", count);
    return 0;
}