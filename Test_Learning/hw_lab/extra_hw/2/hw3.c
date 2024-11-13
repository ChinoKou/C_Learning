#include <stdio.h>

int main () {
    int x, digit[2];
    scanf("%d", &x);
    digit[0] = x % 100;
    digit[1] = x / 100;
    if (digit[1] >= 1 && digit[1] <= 3) {
        printf("%c", digit[0] + 64);
    }
    else if (digit[1] >= 4 && digit[1] <= 6) {
        printf("%c", digit[0] + 96);
    }
    else if (digit[1] >= 7 && digit[1] <= 9) {
        printf("%d", digit[0]);
    }
    return 0;
}