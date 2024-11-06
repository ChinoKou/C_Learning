#include <stdio.h>
#include <string.h>

void strmcpy (char t[], char s[], int m);

int main () {
    char m, s[1000], t[1000];
    printf("请输入字符串s: ");
    scanf("%s", &s);
    printf("请输入开始位置m: ");
    scanf("%d", m);
    strmcpy(t, s, m);
    printf("%s", t);
    return 0;
}

void strmcpy (char t[], char s[], int m) {
    int len = strlen(s);
    for (int i = m - 1; i < len; i++) {
        t[i - m - 1] = s[i + 1];
    }
}