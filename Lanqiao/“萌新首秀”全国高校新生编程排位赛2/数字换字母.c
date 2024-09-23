#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char arr1[10], arr3[100];
    char arr2[10] = {'0','1','2','3','4','5','6','7','8','9'};
    scanf("%10s", arr1);
    scanf("%100s", arr3);
    int n3 = strlen(arr3);
    for (int i1 = 0; i1 <= n3; i1++) {
        for (int i2 = 0; i2 <= 9; i2++) {
            if (arr3[i1] == arr2[i2]) {
                arr3[i1] = arr1[i2];
            }
        }
    }
    printf("%s", arr3);
    return 0;
}