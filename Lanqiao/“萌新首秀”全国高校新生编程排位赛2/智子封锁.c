#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // 请在此输入您的代码
    int a, b, x;
    long long result;
    int arr[4] = {0};
    scanf("%d %d %d", &a, &b, &x);
    result = pow(a, b);
    int numlen = floor(log10(result)) + 1;
    switch (x) {
        case 1:
            if (numlen >= 2) {
                arr[0] = result % 10;
            }
            else if (numlen == 1) {
                arr[0] = result;
            }
            break;
        case 2:
            if (numlen >= 3) {
                arr[0] = result % 10;
                arr[1] = result / 10 % 10;
            }
            else if (numlen == 2) {
                arr[0] = result % 10;
                arr[1] = result / 10;
            }
            break;
        case 3:
            if (numlen >= 4) {
                arr[0] = result % 10;
                arr[1] = result / 10 % 10;
                arr[2] = result / 100 % 10;
            }
            else if (numlen == 3) {
                arr[0] = result % 10;
                arr[1] = result / 10 % 10;
                arr[2] = result / 100; 
            }
            break;
        case 4:
            if (numlen >= 5) {
                arr[0] = result % 10;
                arr[1] = result / 10 % 10;
                arr[2] = result / 100 % 10;
                arr[3] = result / 1000 % 10;
            }
            else if (numlen == 4) {
                arr[0] = result % 10;
                arr[1] = result / 10 % 10;
                arr[2] = result / 100 % 10;
                arr[3] = result / 1000;
            }
            break;
        default:
            printf("error");
            break;
    }
    for (int i = x - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    return 0;
}