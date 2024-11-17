#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    long long arr[n], min;
    scanf("%d", &n);
    int* arr1 = malloc(4 * n);
    for (int i = 0; i < n; i++) {
        *(arr1 + i) = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        *(arr1 + arr[i]) += 1;
        if (i == 0) {
            min = arr[0];
        }
        if (min > arr[i]) {
            min = arr[i];
        }
        printf("%lld %lld\n", min, *(arr1 + min));
    }
    return 0;
}