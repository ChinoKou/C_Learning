#include <stdio.h>

int main () {
    int arr[10] = {12, 485, 56, 2, 4, 645, 14, 58, 652, 178}, x, len;
    scanf("%d", &x);
    len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        if (arr[i] == x) {
            printf("数组中含有该元素 %d , 是第 %d 索引", arr[i], i);
            break;
        }
    }
    return 0;
}