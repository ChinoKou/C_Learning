#include <stdio.h>

int main () {
    char arr[5][100] = {
        "zhangsan",
        "lisi",
        "wangwu",
        "laoliu",
        "zhaoqi"
    };
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}