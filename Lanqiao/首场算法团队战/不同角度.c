#include <stdio.h>

int main () {
    long long n, s, t, input = 0, j = -1, len = 0;
    char arr[1000000];
    scanf("%d", &n);
    while (j < n) {
        arr[input] = getchar();
        if (arr[input] == '\n') {
            j += 1;
        }
        input++;
    }
    for (int i = 1; i < input; i++) {
        if (arr[i] != '\n') {
            len += 1;
        }
        else if (arr[i] == '\n') {
            int count = 0;
            for (int temp = i - len; temp < i; temp++) {
                if (arr[temp] == '9') {
                    count += 1;
                }
            }
            if (count == len) {
                putchar('1');
                for (int temp = i - len; temp < i; temp++) {
                    putchar('0');
                }
            }
            else if (count != len) {
                for (int temp = i - len; temp < i - 1; temp++) {
                    putchar(arr[temp]);
                }
                putchar(arr[i - 1] + 1);
            }
        }
        len = 0;
    }
    return 0;
}