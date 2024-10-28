#include <stdio.h>
#include <math.h>

long long dectobin (int n);

int main () {
    int n;
    printf("输入一个正整数 n : ");
    scanf("%d", &n);
    printf("十进制数 %d 的二进制数是 %lld", n, dectobin(n));
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