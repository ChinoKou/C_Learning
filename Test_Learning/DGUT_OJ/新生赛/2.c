#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int n, arr1[100000];
    long long min;
    scanf("%d", &n);
    long long* arr = (long long*)malloc(n * sizeof(long long));
    memset(arr1, 0, 100000 * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", (arr + i));
        *(arr1 + *(arr + i)) += 1;
        if (i == 0) {
            min = *arr;
        }
        if (min > *(arr + i)) {
            min = *(arr + i);
        }
        printf("%lld %d\n", min, *(arr1 + min));
    }
    free(arr);
    return 0;
}