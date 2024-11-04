#include <stdio.h>

/*
int main() {
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            count += 1;
        }
    }
    printf("%d", count);
}
*/

int main() {
    int count = 0;
    for (int i = 3; i % 3 == 0 && i <= 100; i += 3) {
        count += 1;
    }
    printf("%d", count);
}