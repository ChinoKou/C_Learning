#include <stdio.h>
#include <math.h>

int main () {
    int arr[4] = {0};
    for (int i = 1; i <= 1000; i++) {
        int numlen = floor(log10(i)) + 1;
        if (numlen == 2) {
            arr[0] = i % 10;
            arr[1] = i / 10;
        }
        else if (numlen == 3) {
            arr[0] = i % 10;
            arr[1] = (i / 10) % 10;
            arr[2] = i / 100;
        }
        else if (numlen == 4) {
            arr[0] = i % 10;
            arr[1] = (i / 10) % 10;
            arr[2] = (i / 100) % 10;
            arr[3] = i / 1000;
        }
        int sum = arr[0] + arr[1] + arr[2] + arr[3];
        if (sum == 15) {
            printf("%d\n", i);
        }
    }
    return 0;
}