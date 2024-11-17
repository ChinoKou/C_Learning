#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    long long arr[n], arr1[n], min;
    for (int i = 0; i < n; i++) {
        arr1[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (i == 0) {
            min = arr[0];
        }
        arr1[arr[i]] += 1;
        if (min > arr[i]) {
            min = arr[i];
        }
        printf("%lld %lld\n", min, arr1[min]);
    }
    return 0;
}