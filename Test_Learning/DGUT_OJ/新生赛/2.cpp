#include <iostream>
#include <string.h>
using namespace std;
int main () {
    int n;
    int* arr1 = new int[1000000000000];
    memset(arr1, 0, 1000000000000);
    cin >> n;
    long long min;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
        *(arr1 + *(arr + i)) += 1;
        if (i == 0) min = *arr;
        if (min > *(arr + i)) {
            min = *(arr + i);
        }
        printf("%lld %d\n", min, *(arr1 + min));
    }
    return 0;
}