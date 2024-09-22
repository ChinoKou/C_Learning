#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    for (;;) {
        SetConsoleOutputCP(CP_UTF8);
        int int_n, i, output=1;
        float n;
        printf("请输入 n 的值:\n");
        scanf("%f", &n);
        int_n = (int)n;
        while(n != floor(n) || n <= 0) {
            printf("输入有误，请重新输入:\n");
            scanf("%f", &n);
        }
        for(i = 2; i <= int_n; i++) {
            output = output + i;
        }
        printf("从 1 + ... + 到 %d 的结果是:\n",int_n);
        printf("%d\n", output);
    }
    return 0;
}