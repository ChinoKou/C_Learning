#include <stdio.h>

typedef struct {
    char name[100];
    char stu_num[10];
    int input_order;
    mark marks;
} Stu;

typedef struct{
    char grade;
    int order;
    double scores;
} mark;

double Static (Stu ArrStu[]);

int main () {
    Stu ArrStu[10];
    for (int i = 0; i < 10; i++) {
        printf("\n请输入第 %d 位学生的学号: ", i + 1);
        scanf("%s", ArrStu[i].stu_num);
        printf("请输入第 %d 位学生的姓名: ", i + 1);
        scanf("%s", ArrStu[i].name);
        printf("请输入第 %d 位学生的分数: ", i + 1);
        scanf("%lf", &ArrStu[i].marks.scores);
    }
    double avg = Static(ArrStu);
    printf("平均成绩为: %.2lf", avg);
    return 0;
}

double Static (Stu ArrStu[]) {
    int count_grade[5] = {0, 0, 0, 0, 0};
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        if (ArrStu[i].marks.scores >= 90) {
            ArrStu[i].marks.grade = 'A';
            count_grade[0]++;
        }
        else if (ArrStu[i].marks.scores >= 80 && ArrStu[i].marks.scores < 90) {
            ArrStu[i].marks.grade = 'B';
            count_grade[1]++;
        }
        else if (ArrStu[i].marks.scores >= 70 && ArrStu[i].marks.scores < 80) {
            ArrStu[i].marks.grade = 'C';
            count_grade[2]++;
        }
        else if (ArrStu[i].marks.scores >= 60 && ArrStu[i].marks.scores < 70) {
            ArrStu[i].marks.grade = 'D';
            count_grade[3]++;
        }
        else if (ArrStu[i].marks.scores >= 0 && ArrStu[i].marks.scores < 60) {
            ArrStu[i].marks.grade = 'E';
            count_grade[4]++;
        }
        sum += ArrStu[i].marks.scores;
    }
    //冒泡排序求学生成绩名次
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (ArrStu[i].marks.scores < ArrStu[j].marks.scores) {
                Stu temp = ArrStu[i];
                ArrStu[i] = ArrStu[j];
                ArrStu[j] = temp;
            }
        }
        ArrStu[i].marks.order = i + 1;
    }
    //根据原始排序还原顺序
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; i++) {
            if (ArrStu[i].input_order > ArrStu[j].input_order) {
                Stu temp = ArrStu[i];
                ArrStu[i] = ArrStu[j];
                ArrStu[j] = temp;
            }
        }
    }
    printf("\n学生成绩如下: \n姓名\t 学号\t 成绩\t 等级\t 名次\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t %s\t %.2lf\t %c\t 第 %d 名\n", ArrStu[i].name, ArrStu[i].stu_num, ArrStu[i].marks.scores, ArrStu[i].marks.grade,  ArrStu[i].marks.order);
    }
    for (int i = 0; i < 5; i++) {
        printf("成绩等级为 %c 的有 %d 位同学\n", 65 + i, count_grade[i]);
    }
    return (sum / 10);
}