#include <stdio.h>
#include <string.h>

int main () {
    char arr[5];
    scanf("%s", &arr);
    for (int i = 0; i < 5; i++) {
        arr[i] += 4;
        putchar(arr[i]);
    }
    printf("\n");
    printf("%s", arr);
    return 0;
}