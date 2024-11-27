#include <stdio.h>

int main () {
    int n, arr[6][6];
    printf("请输入一个正整数 n (1 <= n <= 6): ");
    scanf("%d", &n);
    printf("请输入 %d 阶方阵的元素: \n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int max = arr[i][0];
        for (int j = 0; j < n; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (max == arr[i][j]) {
                int min = max;
                for (int h =0 ; h < n; h++) {
                    if (min > arr[h][j]) {
                        min = arr[h][j];
                    }
                }
                if (max == min) {
                    printf("该 %d 阶方阵的鞍点下标为: %d, %d", n, i, j);
                    return 0;
                }
            }
        }
    }
    printf("NO");
    return 0;
}