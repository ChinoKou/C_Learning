#include <stdio.h>

int main () {
    int n, arr[6][6], count = 0;
    printf("请输入一个正整数 n (1 <= n <= 6): ");
    scanf("%d", &n);
    printf("请输入 %d 阶方阵的元素: ", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int saddle_max = arr[i][0];
        for (int j = 0; j < n; j++) {
            if (saddle_max < arr[i][j]) {
                saddle_max = arr[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (saddle_max == arr[i][j]) {
                int saddle_min = saddle_max;
                for (int h =0 ; h < n; h++) {
                    if (saddle_min > arr[h][j]) {
                        saddle_min = arr[h][j];
                    }
                }
                if (saddle_max == saddle_min) {
                    printf("该 %d 阶方阵的鞍点下标为: %d, %d", n, i, j);
                    return 0;
                }
                else {
                    count += 1;
                }
            }
        }
    }
    if (count == n) {
        printf("NO");
    }
    return 0;
}