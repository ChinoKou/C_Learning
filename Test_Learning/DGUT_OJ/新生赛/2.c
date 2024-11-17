#include <stdio.h>

int main () {
    int n, count = 1;
    long long min, arr[n];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (i == 0) {
            min = arr[0];
        }
        if (min > arr[i]) {
            min = arr[i];
            count = 1;
        }
        else if (min == arr[i]) {
            count += 1;
        }
        printf("%lld %d\n", min, count);
    }
    return 0;
}