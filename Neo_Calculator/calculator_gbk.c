#include <stdio.h>
#include <math.h>
#include <windows.h>

double deal();

int main() {
    double output;
    int i;

    printf("=====================================================================\n");
    printf("֧���������㣬֧��ָ�����㣬֧�����Ǻ������㣡\n");
    printf("�밴���¸�ʽ���������ʽ��\n");
    printf("�磺��2 + 3��, ��3��sinֵ����3 s��, ��3��cosֵ����3 c�� \n");
    printf("=====================================================================\n");
    Sleep(2000);
    printf("\n");

    for (i = 1; ; i++) {
        printf("------ִ�е� %d ��------\n", i);
        output = deal();
        if (output == floor(output)) {
            printf("%.0lf\n", output);
        }
        else if (output != floor(output)) {
            printf("%.2lf\n", output);
            printf("�������Ѿ�ȷ��С�������λ��\n");
        }
    }
}

double deal() {

    double num1 = 0, num2 = 0, deal = 0;
    char fuhao = ' ', valid_fuhao[] = "+-*/^sct", sanjiao[] = "sct";

    printf("���������ʽ��");
    scanf("%lf %c %lf", &num1, &fuhao, &num2);
    while (strchr(valid_fuhao, fuhao) == NULL || num2 == 0 && fuhao == '/') {
        if (strchr(valid_fuhao, fuhao) == NULL) {
            printf("�������������, �������������ʽ: \n");
            scanf("%lf %c %lf", &num1, &fuhao, &num2);
        }
        else if (num2 == 0 && fuhao == '/') {
            printf("��������Ϊ0, �������������ʽ: \n");
            scanf("%lf %c %lf", &num1, &fuhao, &num2);
        }
        else {
            printf("������󣡳����˳���\n");
            exit(0);
        }
    }

    switch (fuhao) {
        case '+':
            deal = num1 + num2;
            break;
        case '-':
            deal = num1 - num2;
            break;
        case '*':
            deal = num1 * num2;
            break;
        case '/':
            deal = num1 / num2;
            break;
        case '^':
            deal = pow(num1, num2);
            break;
        case 's':
            deal = sin(num1);
            break;
        case 'c':
            deal = cos(num1);
            break;
        case 't':
            deal = tan(num1);
            break;
        default:
            printf("������󣡳����˳���\n");
            break;
    }

    if (strchr(sanjiao, fuhao) == NULL) {
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

    return (deal);
}