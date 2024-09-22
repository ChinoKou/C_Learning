#include <stdio.h>
#include <math.h>
#include <windows.h>

double deal();

int main() {
    double output;

    output = deal();

    if (output == floor(output)) {
        printf("%.0lf", output);
    }
    else if (output != floor(output)) {
        printf("%.2lf", output);
        printf("计算结果已精确到小数点后两位！");
    }
}

double deal() {

    double num1, num2, output;
    char fuhao;
    char valid_fuhao[] = "+-*/^sct";

    printf("=====================================================================\n");
    printf("支持四则运算，支持指数运算，支持三角函数运算！\n");
    printf("请按以下格式输入计算表达式！\n");
    printf("如：“2 + 3”, 求3的sin值：“3 s”, 求3的cos值：“3 c” \n");
    printf("=====================================================================\n");
    Sleep(2000);
    printf("");
    printf("请输入表达式：\n");
    scanf("%lf %c %lf", &num1, &fuhao, &num2);

    /*
    printf("%c\n", fuhao);
    printf("%c\n", valid_fuhao);
    printf("比较的结果为：\n");
    if (strchr(valid_fuhao, fuhao) == NULL) {
        printf("false\n");
    }
    else if (strchr(valid_fuhao, fuhao) != NULL) {
        printf("true\n");
    }
    system("pause");
    */

    while (strchr(valid_fuhao, fuhao) == NULL || num2 == 0 && fuhao == '/') {
        if (strchr(valid_fuhao, fuhao) == NULL) {
            printf("运算符输入有误, 请重新输入: \n");
            scanf("%lf%c%lf", &num1, &fuhao, &num2);
        }
        else if (num2 == 0 && fuhao == '/') {
            printf("除数不能为0, 请重新输入: \n");
            scanf("%lf%c%lf", &num1, &fuhao, &num2);
        }
        else {
            printf("输入错误！程序退出！\n");
            exit(0);
        }
    }

    switch (fuhao) {
        case '+':
            output = num1 + num2;
            break;
        case '-':
            output = num1 - num2;
            break;
        case '*':
            output = num1 * num2;
            break;
        case '/':
            output = num1 / num2;
            break;
        case '^':
            output = pow(num1, num2);
            break;
        case 's':
            output = sin(num1);
            break;
        case 'c':
            output = cos(num1);
            break;
        case 't':
            output = tan(num1);
            break;
        default:
            printf("输入错误！程序退出！\n");
            break;
    }
    // printf("%lf", output);
    return (output);
}