#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int a, b, x;
    long long result = 1;
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
            if (arr[1] == 0) {
                for (int i = 0; i < 1; i++) {
                        printf("%d", arr[i]);
                }
            }
            else if (arr[1] != 0) {
                for (int i = 0; i < 2; i++) {
                        printf("%d", arr[i]);
                }
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
            if (arr[2] == 0) {
                if (arr[1] == 0) {
                    for (int i = 0; i < 1; i++) {
                        printf("%d", arr[i]);
                    }
                }
                else if (arr[1] != 0) {
                    for (int i = 0; i < 2; i++) {
                        printf("%d", arr[i]);
                    }
                }
            }
            else if (arr[2] != 0) {
                for (int i = 0; i < 3; i++) {
                    printf("%d", arr[i]);
                }
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
            if (arr[3] == 0) {
                if (arr[2] == 0) {
                    if (arr[1] == 0) {
                        for (int i = 0; i < 1; i++) {
                            printf("%d", arr[i]);
                        }
                    }
                    else if (arr[1] != 0) {
                        for (int i = 0; i < 2; i++) {
                            printf("%d", arr[i]);
                        }
                    }
                }
                else if (arr[2] != 0) {
                    for (int i = 0; i < 3; i++) {
                        printf("%d", arr[i]);
                    }
                }
            }
            else if (arr[3] != 0) {
                for (int i = 0; i < 4; i++) {
                    printf("%d", arr[i]);
                }
            }
            break;
        default:
            break;
    }
    return 0;
}