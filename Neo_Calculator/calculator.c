#include <stdio.h>
#include <math.h>
#include <windows.h>

double calculate(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 0;
    }
}

int main() {
    double a, b;
    char op;
    printf("Enter two numbers and an operator (+, -, *, /, ^): ");
    scanf("%lf %lf %c", &a, &b, &op);
    double result = calculate(a, b, op);
    printf("Result: %.2lf\n", result);
    return 0;
}
