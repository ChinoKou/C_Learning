#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main () {
    int arr[] = {0}, temp;
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 481 + 20;
    }
    printf("随机生成的数组：\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < 19; i++) {
        for (int j = i; j < 19; j++) {
            if (arr[i] < arr[j + 1]) {
                temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n冒泡排序后的数组: \n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
}