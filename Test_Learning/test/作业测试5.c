#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000000];
    scanf("%s", str);
    int len = strlen(str);
    char* begin = str;
    char* end = str + len - 1;
    char temp;
    while(begin <= end) {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }

    printf("翻转后的字符串：%s",str);
}