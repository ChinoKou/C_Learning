#include <stdio.h>

int main () {
    char letter;
    scanf("%c", &letter);
    if (letter >= 65 && letter <= 90) {
        printf("大写");
    }
    else if (letter >= 97 && letter <= 122) {
        printf("小写");
    }
    return 0;
}