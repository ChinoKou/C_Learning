#include <iostream>

using namespace std;

int main () {
    int n, a[6][6], max, min, temp;
    cout << "请输入一个正整数 n (1 <= n <= 6): ";
    cin >> n;
    cout << "请输入 " << n << " 阶方阵的元素: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == 0 && j == 0) {
                min = max = a[i][j];
            }
            if (min > a[i][j]) {
                min = a[i][j];
            }
            if (max < a[i][j]) {
                max = a[i][j];
            }
        }
    }
    cout << "交换最大最小值后的 " << n << " 阶方阵结果:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (min == a[i][j]) {
                cout << max << " ";
            }
            else if (max == a[i][j]) {
                cout << min << " ";
            }
            else {
                cout << a[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}