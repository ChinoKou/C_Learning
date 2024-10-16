#include <stdio.h>

int main () {
    int eat = 1;
    for (int i = 1; i <= 9; i++) {
        eat += 1;
        eat *= 2;
    }
    printf("猴子第一天共摘了 %d 个桃子", eat);
    return 0;
}