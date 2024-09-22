#include <stdio.h>
#include <windows.h>
#include <math.h>

float function(float num1, float num2, char fuhao);
float deal();

int main() {
    SetConsoleOutputCP(CP_UTF8);

    float n, output;
    int int_n, i;

    printf("请输入执行次数(-1即为无限):\n");

    scanf("%f", &n);
    while (n != floor(n) || n < 0 && n != -1) {
        printf("输入的次数有误，必须为整数(或-1)，请重新输入执行次数!\n");
        scanf("%f", &n);
    }

    int_n = (int)n;

    if (int_n == -1) {
        printf("执行次数设置为无限。\n");
        printf("程序将无限循环，请按 Ctrl+C 结束。\n");
    }
    else if (int_n > 0) {
        printf("执行次数设置为%d。\n", int_n);
    }

    if (int_n != -1) {
        for (i = 1; i <= int_n; i++) {
            printf("---执行第 %d 次---\n", i);

            output = deal();

            if (output == floor(output)) {
                printf("%.0f\n", output);
                printf("\n");
            }
            else if (output != floor(output)) {
                printf("%.2f\n", output);
                printf("计算结果精确到小数点后两位！\r\n");
                printf("\n");
            }
        }
    }
    else if (int_n == -1) {
        for (i = 1; ; i++) {
            printf("---执行第 %d 次---\n", i);

            output = deal();

            if (output == floor(output)) {
                printf("%.0f\n", output);
                printf("\n");
            }
            else if (output != floor(output)) {
                printf("%.2f\n", output);
                printf("计算结果精确到小数点后两位！\r\n");
                printf("\n");
            }
        }
    }

    printf("按下任意键后程序结束。\n");
    system("pause");
    return 0;
}

float deal() {

    float num1, num2;
    float a = 0;
    char fuhao;
    char valid_fuhaos[] = "+-*/^sct";
    char sanjiao[] = "sct";

    printf("请输入第一个数字:\r\n");
    scanf("%f", &num1);

    printf("请输入运算符:\r\n");
    printf("(输入 s,c,t 则忽略第二个数字,直接计算第一个数字的正余弦值与正切值!)\r\n");
    scanf(" %c", &fuhao);

    while (strchr(valid_fuhaos, fuhao) == NULL) {
        printf("输入的运算符有误(不支持此运算符)，请重新输入运算符:\r\n");
        scanf(" %c", &fuhao);
        printf("\r\n");
    }

    if (strchr(sanjiao, fuhao) == NULL) {
        printf("请输入第二个数字:\r\n");
        scanf("%f", &num2);

        while (num2 == 0 && fuhao == '/') {
            printf("除数不能为 0 \n请重新输入第二个数字:\r\n");
            scanf("%f", &num2);
        }
    }

    a = function(num1, num2, fuhao);

    if (strchr(sanjiao, fuhao) != NULL) {
        if (fuhao == 's') {
            printf("sin (%.2f) = \n", num1);
        }
        else if (fuhao == 'c') {
            printf("cos (%.2f) = \n", num1);
        }
        else if (fuhao == 't') {
            printf("tan (%.2f) = \n", num1);
        }
    }
    else if (strchr(sanjiao, fuhao) == NULL) {
        printf("%.2f %c %.2f = \n", num1, fuhao, num2);
    }

    Sleep(500);
    return (a);
}

float function(float num1, float num2, char fuhao) {

    float c = 0;

    if (fuhao == '+') {
        c = num1 + num2;
    }
    else if (fuhao == '-') {
        c = num1 - num2;
    }
    else if (fuhao == '*') {
        c = num1 * num2;
    }
    else if (fuhao == '/') {
        c = num1 / num2;
    }
    else if (fuhao == '^') {
        c = pow(num1, num2);
    }
    else if (fuhao == 's') {
        c = sin(num1);
    }
    else if (fuhao == 'c') {
        c = cos(num1);
    }
    else if (fuhao == 't') {
        c = tan(num1);
    }
    return (c);
}