#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

int deal();
void error(int flag);
void function(double num1, char op, double num2, double* sum);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    printf("=====================================================================\n");
    printf("支持四则运算，支持指数运算，支持三角函数运算！\n");
    printf("按以下格式输入计算表达式！\n");
    printf("如: “2+3”” \n");
    printf("=====================================================================\n");
    //Sleep(2000);
    printf("\n");
    printf("请输入计算表达式: ");

    double* result = malloc(sizeof(double));
    for (int i = 1; ; i++) {
        printf("------执行第 %d 次------\n", i);
        int flag = deal(result);
        if (!flag) {
            printf("计算结果为: %.2lf\n", *result);
            continue;
        }
        error(flag);
    }
    free(result);
    return 0;
}

int deal(double* result) {
    char valid_characters[] = "+-*/^";
    double num1, num2;
    *result = 0;
    char* endptr, *s = malloc(10000 * sizeof(char));
    scanf("%s", s);
    num1 = strtod(s, &endptr);
    for (int i = 0; i < strlen(s); ) {
        i = endptr - s;
        if (strchr(valid_characters, s[i]) == NULL) {
            return 1;
        }
        num2 = strtod(endptr, &endptr);
        if (num2 == 0 && s[i] == '/') {
            return 2;
        }
        function(num1, s[i], num2, result);
        num1 = strtod(endptr, &endptr);
    }
    return 0;
}

void function(double num1, char op, double num2, double* sum) {
    switch (op) {
        case '+':
            *sum += num1 + num2;
        case '-':
            *sum += num1 - num2;
        case '*':
            *sum += num1 * num2;
        case '/':
            *sum += num1 / num2;
        case '^':
            *sum += pow(num1, num2);
    }
}

void error(int error_code) {
    switch (error_code) {
        case 1:
            printf("输入的计算符号不合法，请重新输入！\n");
            break;
        case 2:
            printf("除数不能为0，请重新输入！\n");
            break;
        case 3:
            printf("输入的表达式不合法，请重新输入！\n");
            break;
        default:
            printf("未知错误，请重新输入！\n");
    }
}