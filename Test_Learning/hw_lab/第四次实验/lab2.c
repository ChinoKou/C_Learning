#include <stdio.h>

int main () {
    int n, del, arr[9], temp;
    printf("输入数据的个数 n (1 <= n <= 8): ");
    scanf("%d", &n);
    printf("输入 %d 个互不相同的整数: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("输入要删除的整数: ");
    scanf("%d", &del);
    printf("删除 %d 后的排序结果: ", del);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            if (arr[i] > arr[j + 1]) {
                temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (del == arr[i]) {
            continue;
        }
        printf("%d ", arr[i]);
    }
    return 0;
}