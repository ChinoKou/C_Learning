#include <iostream>
using namespace std;
int main () {
    int n, count = 0;
    int* arr1 = new int[1000000000000];
    cin >> n;
    long long min;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    min = *arr;
    for (int i = 0; i < n; i++) {
        if (min > *(arr + i)) {
            min = *(arr + i);
            count = 1;
        }
        else if (min == *(arr + i)) {
            count++;
        }
        printf("%lld %d\n", min, count);
    }
    return 0;
}