#include <stdio.h>

int main () {
    int arr[9] = {1, 3, 4, 5, 6, 7, 1, 3, 4}, temp;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len / 2; i++) {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}