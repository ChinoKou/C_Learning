#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a < b;
}
int main() {
    int n;
    scanf("%d", &n);
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n, cmp);
    printf("排序后的数组为: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    return 0;
}