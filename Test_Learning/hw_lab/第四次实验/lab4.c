#include <stdio.h>

int main() {
    int n, arr[6][6]; 
    printf("请输入一个正整数 n (1 <= n <= 6): ");
    scanf("%d", &n);
    printf("请输入 %d 阶方阵的元素: ", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            scanf("%d", &arr[i][j]);
    }
    for (int i = 0; i < n; i++) {
        int max = *(*arr + i);
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(arr + j) + i));
            if (max < (*(*(arr + j) + i))) {
                max = (*(*(arr + j) + i));
            }
        }
        for (int j = 0; j < n; j++) {
            if (max == *(*(arr + j) + i)) {
                int min = max;
                for (int h = 0 ; h < n; h++) {
                    if (min > *(*(arr + j) + h)) {
                        min = *(*(arr + j) + h);
                    }
                }
                if (max == min) {
                    printf("该 %d 阶方阵的鞍点下标为: %d, %d", n, i, j);
                    return 0;
                }
            }
        }
    }
    return 0;
}