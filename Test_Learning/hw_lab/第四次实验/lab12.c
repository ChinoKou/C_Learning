#include <stdio.h>

typedef struct {
    char name[100];
    char stu_num[10];
    double marks;
} Stu;

double Static (Stu ArrStu[]);

int main () {
    Stu ArrStu[10];
    for (int i = 0; i < 10; i++) {
        printf("\n请输入第 %d 位学生的学号: ", i + 1);
        scanf("%s", ArrStu[i].stu_num);
        printf("请输入第 %d 位学生的姓名: ", i + 1);
        scanf("%s", ArrStu[i].name);
        printf("请输入第 %d 位学生的分数: ", i + 1);
        scanf("%lf", &ArrStu[i].marks);
    }
    double avg = Static(ArrStu);
    printf("平均成绩为: %.2lf", avg);
    return 0;
}

double Static (Stu ArrStu[]) {
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
        for (int j = i; j < 10; j++) {
            if (ArrStu[i].marks < ArrStu[j].marks) {
                Stu temp = ArrStu[i];
                ArrStu[i] = ArrStu[j];
                ArrStu[j] = temp;
            }
        }
    }
    printf("\n学生成绩排序如下: \n名次\t 姓名\t 学号\t 成绩\t\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t %s\t %s\t %.2lf\t\n", i + 1, ArrStu[i].name, ArrStu[i].stu_num, ArrStu[i].marks);
    }
    for (int i = 0; i < 5; i++) {
        printf("成绩等级为 %c 的有 %d 位同学\n", char_grade[i], grade[i]);
    }
    return (sum / 10);
}