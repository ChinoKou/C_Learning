#include <stdio.h>
#include <string.h>

int main () {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 32 && s[i + 1] >= 97 && s[i + 1] <= 122) {
            s[i + 1] -= 32;
        }
    }
    printf("%s", s);
    return 0;
}