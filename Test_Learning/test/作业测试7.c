#include <stdio.h>
typedef union {
    long i;
    int k[5];
    char c;
} DATE;
struct date{
    int cat;
    DATE cow;
    double dog;
} too;
DATE max;

int main() {
    printf("%d", sizeof(struct data) + sizeof(max));
}