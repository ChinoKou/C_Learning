#include <stdio.h>

int main () {
    int n, a[6][6], max, min, temp;
    printf("请输入一个正整数 n (1 <= n <= 6): ");
    scanf("%d", &n);
    printf("请输入 %d 阶方阵的元素: ", n);
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
    printf("交换最大最小值后的 %d 阶方阵结果:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (min == a[i][j]) {
                printf("%d ", max);
            }
            else if (max == a[i][j]) {
                printf("%d ", min);
            }
            else {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}