#include <stdio.h>
#include <math.h>

int main () {
    int n;
    scanf("%d", &n);
    if (floor(log2(n)) == log2(n)) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}