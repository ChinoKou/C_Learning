#include <stdio.h>
#include <string.h>
int main() {
    char str[1000000];
    scanf("%s", str);
    int len = strlen(str);
    char* begin = str;
    char* end = str + len - 1;
    char temp;
    for (int i = 0; i < (len / 2); i++) {
        temp = *(begin + i);
        *(begin + i) = *(end - i);
        *(end - i) = temp;
    }
    printf("翻转后的字符串：%s",str);
    return 0;
}