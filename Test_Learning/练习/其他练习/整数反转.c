#include <stdio.h>
#include <string.h>

int main () {
    char num[100];
    scanf("%s", num);
    int len = strlen(num);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", num[i]);
    }
    return 0;
}