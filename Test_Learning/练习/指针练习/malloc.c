#include <stdio.h>
#include <stdlib.h>

void p_print(int* arr, int n);

int main () {
    int n;
    scanf("%d", &n);
    int arr[n];
    int* p = arr;
    p_print(arr, n);
    return 0;
}

void p_print (int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
}