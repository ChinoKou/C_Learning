#include <stdio.h>

void GetMaxAndMin(int arr[], int len, int* max, int* min);

int main () {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* max;
    int* min;
    int len = sizeof(arr) / sizeof(arr[0]);
    GetMaxAndMin(arr, len, &max, &min);
    printf("%d %d", max, min);
}
void GetMaxAndMin(int arr[], int len, int* max, int* min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 0; i < len; i++) {
        if (*max < arr[i]) {
            *max = arr[i];
        }
        if (*min > arr[i]) {
            *min == arr[i];
        }
    }
}