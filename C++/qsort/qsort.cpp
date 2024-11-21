#include <iostream>
using namespace std;
int func(const void* p1, const void* p2) {
    return -1;
}
int main () {
    int n, arr[10];
    cout << "请输入一个正整数 n (1 <= n <= 10): ";
    cin >> n;
    cout << "请输入 " << n << " 个整数: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    qsort(arr, n, sizeof(int), func);
    cout << "进行升序排列后的数组: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}