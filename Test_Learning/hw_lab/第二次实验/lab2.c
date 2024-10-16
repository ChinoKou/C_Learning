#include <stdio.h>

int main () {
    int x, point;
    printf("请输入学生的百分制成绩:\n");
    scanf("%d", &x);
    if (x >= 90 && x <= 100) {
        point = 1;
    }
    else if (x >= 80 && x < 90) {
        point = 2;
    }
    else if (x >= 70 && x < 80) {
        point = 3;
    }
    else if (x >= 60 && x < 70) {
        point = 4;
    }
    else if (x >= 0 && x < 60) {
        point = 5;
    }
    switch (point) {
        case 1:
            printf("该学生的五级制成绩为: A ,百分制成绩为：%d", x);
            break;
        case 2:
            printf("该学生的五级制成绩为: B ,百分制成绩为：%d", x);
            break;
        case 3:
            printf("该学生的五级制成绩为: C ,百分制成绩为：%d", x);
            break;
        case 4:
            printf("该学生的五级制成绩为: D ,百分制成绩为：%d", x);
            break;
        case 5:
            printf("该学生的五级制成绩为: E ,百分制成绩为：%d", x);
            break;
        default:
            break;
    }
    return 0;
}