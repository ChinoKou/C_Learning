#include <stdio.h>
#include <string.h>

int main () {
    char s[1000];
    scanf("%s", &s);
    //无法输入空格
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '\0') {
            s[i + 1] += 20;
        }
    }
    printf("%s", s);
    return 0;
}