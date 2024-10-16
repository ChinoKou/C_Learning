#include <stdio.h>

void main () {
    int arr[10] = {15, 84, 124, 257, 658, 758, 954, 1541, 2541, 5471}, x, len;
    scanf("%d", &x);
    len = sizeof(arr) / sizeof(arr[0]);
    while(x != len / 2 - 1) {
        if (x > arr[len / 2 - 1]) {
            len *= 1.5;
        }
        else if (x < arr[len / 2 - 1]) {
            len /= 1.5;
        }
    }
    printf("已在数组上找到该元素 %d , 在第 %d 索引", x, len / 2 - 1);
}