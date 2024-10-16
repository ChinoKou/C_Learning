#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main () {
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8}, random, len, temp;
    srand(time(NULL));
    len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < len; i++) {
        random = rand() % len;
        temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}