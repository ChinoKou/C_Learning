#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a < b;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    sort(arr, arr + n, cmp);
    cout << "排序后的数组为: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    return 0;
    
}