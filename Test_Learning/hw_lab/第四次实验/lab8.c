#include <stdio.h>
#include <string.h>

void sort (char* s);
int main () {
    char s[5][100];
    for (int i = 0; i < 5; i++) {
        scanf("%s", s[i]);
    }

    printf("%s", s);
    return 0;
}

void sort (char* s) {
    
}