#include <stdio.h>

void sort (int* list, int n);

int main () {
    int n, arr[10];
    printf("请输入一个正整数 n (1 <= n <= 10): ");
    scanf("%d", &n);
    printf("请输入 %d 个整数: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("进行升序排列后的数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void sort (int* list, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (*(list + i) > *(list + j)) {
                temp = *(list + i);
                *(list + i) = *(list + j);
                *(list + j) = temp;
            } 
        }
    }
}