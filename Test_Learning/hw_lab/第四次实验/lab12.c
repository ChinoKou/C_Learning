#include <stdio.h>

typedef struct student {
    char name[100];
    char stu_num[10];
    double marks;
}stu;

double Static (stu ArrStu[]);

int main () {
    stu ArrStu[10];
    for (int i = 0; i < 10; i++) {
        printf("\n请输入第 %d 位学生的学号: ", i + 1);
        scanf("%s", ArrStu[i].stu_num);
        printf("请输入第 %d 位学生的姓名: ", i + 1);
        scanf("%s", ArrStu[i].name);
        printf("请输入第 %d 位学生的分数: ", i + 1);
        scanf("%lf", ArrStu[i].marks);
    }
    double avg = Static(ArrStu);
    printf("平均成绩为: %lf", avg);
    return 0;
}

double Static (stu ArrStu[]) {
    int grade[5] = {0, 0, 0, 0, 0};
    char char_grade[6] = "ABCDE";
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        if (ArrStu[i].marks >= 90) {
            grade[0]++;
        }
        else if (ArrStu[i].marks >= 80 && ArrStu[i].marks < 90) {
            grade[1]++;
        }
        else if (ArrStu[i].marks >= 70 && ArrStu[i].marks < 80) {
            grade[2]++;
        }
        else if (ArrStu[i].marks >= 60 && ArrStu[i].marks < 70) {
            grade[3]++;
        }
        else if (ArrStu[i].marks >= 0 && ArrStu[i].marks < 60) {
            grade[4]++;
        }
        sum += ArrStu[i].marks;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 9; j++) {
            if (ArrStu[i].marks < ArrStu[j].marks) {
                stu temp = ArrStu[i];
                ArrStu[i] = ArrStu[j];
                ArrStu[j] = temp;
            }
        }
    }
    printf("学生成绩排序如下: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d %s %s %d\n", i, ArrStu[i].name, ArrStu[i].stu_num, ArrStu[i].marks);
    }
    for (int i = 0; i < 5; i++) {
        printf("成绩等级为 %c 的有 %d 位同学\n", char_grade[i], grade[i]);
    }
    return (sum / 10);
}