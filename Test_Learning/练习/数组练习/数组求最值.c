#include <stdio.h>

void main () {
    int arr[] = {2,5,7,1,5,8,4,1,668,4651,3,46,1,5,65,4,456,5,35,15,65,465,45,8,78,21,1,53};
    int len = sizeof(arr) / sizeof(int), max = arr[0];
    for (int i = 0; i < len; i++) {
        max = max > arr[i + 1] ? max : arr[i + 1];
    }
    printf("最大值为: %d", max);
}