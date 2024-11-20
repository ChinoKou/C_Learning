#include <stdio.h>

int main () {
    int n, count = 0;
    scanf("%d", &n);
    long long min, arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    min = arr[0];
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
            count = 1;
        }
        else if (min == arr[i]) {
            count++;
        }
        printf("%lld %d\n", min, count);
    }
    return 0;
}