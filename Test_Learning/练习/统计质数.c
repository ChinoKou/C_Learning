#include <stdio.h>
#include <math.h>

int main () {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= i; j++) {
            if (j < i ) {
                printf("%d是质数\n", i);
            }
        }
    }
    return 0;
}