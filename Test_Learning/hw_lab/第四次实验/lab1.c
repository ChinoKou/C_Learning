#include <stdio.h>

int main () {
    int n, arr[10], temp;
    printf("请输入一个正整数 n (1 <= n <= 10): ");
    scanf("%d", &n);
    printf("请输入 %d 个互不相同的整数: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (min == arr[i]) {
            temp = arr[0];
            arr[0] = min;
            arr[i] = temp;
        }
        else if (max == arr[i]) {
            temp = arr[n - 1];
            arr[n - 1] = max;
            arr[i] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}