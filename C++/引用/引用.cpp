#include <iostream>
#include <math.h>
using namespace std;

long long dectobin (int n);

int main () {
    int n;
    cout << "输入一个正整数 n : ";
    cin >> n;
    cout << "十进制数 " << n << " 的二进制数是 " << dectobin(n);
    return 0;
}

long long dectobin (int n) {
    long long temp, result = 0;
    for (int i = 0; n > 0; i++) {
        temp = n % 2;
        n /= 2;
        result += temp * pow(10, i);
    }
    return result;
}