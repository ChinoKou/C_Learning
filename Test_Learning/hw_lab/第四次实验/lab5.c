#include <stdio.h>

int main () {
    char ch = getchar();
    while (ch != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + 'Z' - ch;
        }
        putchar(ch);
        ch = getchar();
    }
    return 0;
}