#include <stdio.h>

int main () {
    int n, arr[10][10], sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            if ((i + j) == (n - 1) || i == j) {
                sum += arr[i][j];
            }
        }
    }
    printf("%d", sum);
    return 0;
}