#include <stdio.h>

int main () {
    int n, a[6][6], max, min, temp, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i == 0 && j == 0) {
                min = max = a[i][j];
            }
            if (min > a[i][j]) {
                min = a[i][j];
            }
            if (max < a[i][j]) {
                max = a[i][j];
            }
        }
    }
    for (int i0 = 0; i0 < n; i0++) {
        for (int j0 = 0; j0 < n; j0++) {
            if (min == a[i0][j0] && !count) {
                count++;
                for (int i1 = 0; i1 < n; i1++) {
                    for (int j1 = 0; j1 < n; j1++) {
                        if (max == a[i1][j1]) {
                            temp = a[i0][j0];
                            a[i0][j0] = a[i1][j1];
                            a[i1][j1] = temp;
                            break;
                        }
                    }
                }
            }
            printf("%d ", a[i0][j0]);
        }
        printf("\n");
    }
    return 0;
}