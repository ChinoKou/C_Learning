#include <stdio.h>
#include <string.h>

void sort (char(*s)[100]);
int main () {
    char s[5][100];
    for (int i = 0; i < 5; i++) {
        scanf("%s", s[i]);
    }
    sort(s);
    return 0;
}

void sort (char(*s)[100]) {
    for (int i = 0; i < 5; i++) {
        for (int j = i; i < 5; j++) {
            if (*(*s + i) < *(*s + j)) {
                char temp[100];
                strcpy(temp, (*s) + i);
                strcpy((*s) + i, (*s) + j);
                strcpy((*s) + j, temp);
            }
        }
    }
}