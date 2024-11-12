#include <stdio.h>

int main () {
    int arr1[3] = {1, 2, 3};
    int arr2[5] = {11, 22, 33, 44, 55};
    int arr3[7] = {111, 222, 333, 444, 555, 666, 777};
    int* arr = {arr1, arr2, arr3};
    for (int i = 0; i < 3; i++) {
        int len = sizeof(arr[i]);
    }
    return 0;
}