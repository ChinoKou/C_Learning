#include <stdio.h>

int main () {
    int x = 0, y = 0;
    char ch;
    scanf("%c", &ch);
    while (ch != '\n') {
        if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122) {
            y += 1;
        }
        x += 1;
        scanf("%c", &ch);
    }
    printf("x = %d, y = %d\n" , x, y);
    return 0;
}