#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int arr[100000] = {0}, sum = 0, avg, count = 0, len;
    srand(time(NULL));
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    len = sizeof(arr) / sizeof(int);
    avg = sum / len;
    for (int i = 0; i < len; i++) {
        if (arr[i] < avg) {
            count += 1;
        }
    }
    printf("\n数组所有数据和为: %d \n所有数据平均数为: %d \n有 %d 个数据比平均值小\n", sum, avg, count);
    return 0;
}