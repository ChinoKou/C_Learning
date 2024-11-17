#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    long long min;
    scanf("%d", &n);
    long long* arr1 = malloc(8 * n);
    long long* arr = malloc(8 * n);
    for (int i = 0; i < n; i++) {
        *(arr1 + i) = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", (arr + i));
        *(arr1 + *(arr + i)) += 1;
        if (i == 0) {
            min = *arr;
        }
        if (min > *(arr + i)) {
            min = *(arr + i);
        }
        printf("%lld %lld\n", min, *(arr1 + min));
    }
    return 0;
}