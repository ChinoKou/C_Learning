#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int output = 0;
    output = a++ + ++a - --b - a--;
    // 10 + 12 - 4 - 12
    printf("%d", output);
}