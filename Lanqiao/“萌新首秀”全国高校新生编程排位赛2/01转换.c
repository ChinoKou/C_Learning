#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    char arr[100];
    scanf("%100s", arr);
    int len = strlen(arr);
    if (arr[len - 1] == '0') {
        arr[len - 1] = '1';
    }
    else if (arr[len - 1] == '1') {
        arr[len - 1] = '0';
    }
    printf("%s", arr);
}