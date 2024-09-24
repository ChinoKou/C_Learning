#include <stdio.h>

int main () {
    float n = 0.1;
    int count = 0;
    for ( ; n <= 8844430; n *= 2) {
        count += 1;
    }
    printf("%d", count);
    return 0;
}