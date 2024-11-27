#include <stdio.h>

int main() {
    int m;
    while (1) {
    scanf("%d", &m);
    int i = m;
    printf("%d\n", (i == 4 || i == 6 || i == 9 || i == 11));
    }
}