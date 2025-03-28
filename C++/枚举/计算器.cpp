#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

double deal();
int print(double num1, double num2, char fuhao);
double function(double num1, double num2, char fuhao);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double output;
    int i;

    printf("=====================================================================\n");
    printf("支持四则运算，支持指数运算，支持三角函数运算！\n");
    printf("请按以下格式输入计算表达式！\n");
    printf("如: “2 + 3”, 求3的sin值: “3 s”, 求3的cos值: “3 c” \n");
    printf("如: “3 ^ 2”, 求3的e值: “3 e 随便一个数”, 求2的lg\ln值: “3 g 随便一个数” \n");
    printf("=====================================================================\n");
    Sleep(2000);
    printf("\n");

    for (i = 1; ; i++) {
        printf("------执行第 %d 次------\n", i);
        output = deal();
        if (output == floor(output)) {
            printf("%.0lf\n", output);
        }
        else if (output != floor(output)) {
            printf("%.2lf\n", output);
            printf("计算结果已精确到小数点后两位！\n");
        }
    }
}

double deal() {
    double num1, num2, calculate_output;
    char fuhao, valid_fuhao[] = "+-*/^sctegn";

    printf("请输入计算式：");
    scanf("%lf %c %lf", &num1, &fuhao, &num2);
        while (strchr(valid_fuhao, fuhao) == NULL || num2 == 0 && fuhao == '/') {
        if (strchr(valid_fuhao, fuhao) == NULL) {
            printf("运算符输入有误, 请重新输入计算式: \n");
            scanf("%lf %c %lf", &num1, &fuhao, &num2);
        }
        else if (num2 == 0 && fuhao == '/') {
            printf("除数不能为0, 请重新输入计算式: \n");
            scanf("%lf %c %lf", &num1, &fuhao, &num2);
        }
        else {
            printf("输入错误！程序退出！\n");
            exit(0);
        }
    }

    calculate_output = function(num1, num2, fuhao);

    print(num1, num2, fuhao);

    return (calculate_output);
}

double function(double num1, double num2, char fuhao) {
    enum chara {};
    switch (fuhao) {
        case '+':
            return (num1 + num2);
        case '-':
            return (num1 - num2);
        case '*':
            return (num1 * num2);
        case '/':
            return (num1 / num2);
        case '^':
            return (pow(num1, num2));
        case 's':
            return (sin(num1));
        case 'c':
            return (cos(num1));
        case 't':
            return (tan(num1));
        case 'e':
            return (exp(num1));
        case 'g':
            return (log10(num1));
        case 'n':
            return (log(num1));
        default:
            printf("ERROR!\n");
            break;
    }
}

int print(double num1, double num2, char fuhao) {
    char sanjiao[] = "sct";

    if (strchr(sanjiao, fuhao) == NULL && fuhao != 'e' && fuhao != 'n' && fuhao != 'g') {
        if (num1 == floor(num1) && num2 == floor(num2)) {
            printf("%.0lf %c %.0lf = ", num1, fuhao, num2);
        }
        else if (num1 != floor(num1) && num2 != floor(num2)) {
            printf("%.2lf %c %.2lf = ", num1, fuhao, num2);
        }
        else if (num1 != floor(num1) && num2 == floor(num2)) {
            printf("%.2lf %c %.0lf = ", num1, fuhao, num2);
        }
        else if (num1 == floor(num1) && num2 != floor(num2)) {
            printf("%.0lf %c %.2lf = ", num1, fuhao, num2);
        }
    }
    else if (strchr(sanjiao, fuhao) != NULL) {
        if (num1 == floor(num1)) {
            if (fuhao = 's') {
                printf("sin(%.0lf) = ", num1);
            }
            else if (fuhao = 'c') {
                printf("(%.0lf) = ", num1);
            }
            else if (fuhao = 't') {
                printf("(%.0lf) = ", num1);
            }
        }
        else if (num1 != floor(num1)) {
            if (fuhao = 's') {
                printf("sin(%lf) = ", num1);
            }
            else if (fuhao = 'c') {
                printf("cos(%lf) = ", num1);
            }
            else if (fuhao = 't') {
                printf("tan(%lf) = ", num1);
            }
        }
    }
    else if (fuhao == 'e' || fuhao == 'g' || fuhao == 'n') {
        if (num1 == floor(num1)) {
            if (fuhao == 'e') {
                printf("e^(%.0lf) = ", num1);
            }
            else if (fuhao == 'g') {
                printf("lg(%.0lf) = ", num1);
            }
            else if (fuhao == 'n') {
                printf("ln(%.0lf) = ", num1);
            }
        } 
        else if (num1 != floor(num1)) {
            if (fuhao == 'e') {
                printf("e^(%lf) = ", num1);
            }
            else if (fuhao == 'g') {
                printf("lg(%lf) = ", num1);
            }
            else if (fuhao == 'n') {
                printf("ln(%lf) = ", num1);
            }
        }
    }
}
