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
    printf("互换后的 n 个整数依次是: ");
    printf("%d ", min);
    for (int i = 1; i < n - 1; i++) {
        if (min == arr[i]) {
            printf("%d ", arr[0]);
        }
        else if (max == arr[i]) {
            printf("%d ", arr[n-1]);
        }
        else {
            printf("%d ", arr[i]);
        }
    }
    printf("%d ", max);
    return 0;
}