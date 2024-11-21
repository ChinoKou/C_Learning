#include <iostream>
using namespace std;

int main() {
    int n, arr[6][6], count = 0; 
    cout << "请输入一个正整数 n (1 <= n <= 6): ";
    cin >> n;
    cout << "请输入 " << n << " 阶方阵的元素: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> *(*(arr + j) + i);
    }
    for (int i = 0; i < n; i++) {
        int max = *(*arr + i);
        for (int j = 0; j < n; j++) {
            if (max < *(*(arr + j) + i)) max = *(*(arr + j) + i);
        }
        for (int j = 0; j < n; j++) {
            if (max == *(*(arr + j) + i)) {
                int min = max;
                for (int h =0 ; h < n; h++) {
                    if (min > *(*(arr + j) + h)) min = *(*(arr + j) + h);
                }
                if (max == min) {
                    cout << "该 " << n << " 阶方阵的鞍点下标为: " << i << ", " << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}