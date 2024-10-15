#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main () {
    int arr[10] = {0}, temp, count = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;
    }
    printf("随机生成的数组：\n");
    for (int i = 1; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i] <= arr[i + 1]) {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        count = 0;
        for (int j = 0; j < 9; j++) {
            if (arr[i] >= arr[i + 1]) {
                count += 1;
            }
        }
        if (count == 9) {
            break;
        }
    }
    printf("\n冒泡排序后的数组: \n");
    for (int i = 1; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}