#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n;
    long long min;
    scanf("%d", &n);
    long long* arr1 = (long long*)malloc(1000000000000LL * sizeof(long long));
    long long* arr = (long long*)malloc(n * sizeof(long long));
    memset(arr1, 0, 1000000000000LL * sizeof(long long));
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
    free(arr);
    free(arr1);
    return 0;
}