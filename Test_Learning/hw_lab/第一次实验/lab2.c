#include <stdio.h>

int main () {
    int sum = 0, count = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 != 0) {
            sum += i;
            count ++;
        }
    }
    printf("sum = %d, count = %d, average = %d", sum, count, sum / count);
    return 0;
}