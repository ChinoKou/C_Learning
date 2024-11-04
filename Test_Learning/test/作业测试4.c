#include <stdio.h>
#define N 2
#define M N+1
#define NUM (M+1)*M/2

int main () {
    int i = 1, n = 0;
    while(i<=NUM) {
        n++;
        printf("%d",n);
        i++;
    }
    printf("\n");
}