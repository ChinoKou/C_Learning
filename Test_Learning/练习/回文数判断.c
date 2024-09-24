#include <string.h>
#include <stdio.h>
#include <math.h>

int main () {
    char str[100];
    int count = 0;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i + 1 <= len / 2; i++) {
        if (str[i] == str[len - i - 1]) {
            count += 1;
        }
        if (count == len / 2 && floor(len / 2) == len / 2) {
            printf("yes");
        }
        else if (count == len / 2 - 0.5) {
            printf("yes");
        }
        else {
            
        }
    }
    return 0;
}