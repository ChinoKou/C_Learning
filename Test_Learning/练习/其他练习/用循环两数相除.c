#include <stdio.h>

int main () {
    int a, b, shang = 1;
    scanf("%d %d", &a, &b);
    int i = b;
    while (i + b <= a) {
        i += b;
        shang += 1;
    }
    printf("商为：%d, 余数为: %d", shang, (a - i));
    return 0;
}