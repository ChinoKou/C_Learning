#include <stdio.h>

typedef struct {
    char grade;
    int order;
    double scores;
} mark;

typedef struct {
    char name[100];
    char stu_num[10];
    int input_order;
    mark marks;
} Stu;

double Static (Stu* ArrStu, int* count_grade);

int main () {
    Stu ArrStu[10];
    int count_grade[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 10; i++) {
        printf("请输入第 %d 位学生的学号, 姓名和分数: ", i + 1);
        scanf("%s %s %lf", ArrStu[i].stu_num, ArrStu[i].name, &ArrStu[i].marks.scores);
        ArrStu[i].input_order = i + 1;
    }
    double avg = Static(ArrStu, count_grade);
    printf("\n学生成绩如下: \n姓名\t 学号\t  成绩\t 等级\t 名次\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t %s  %.1lf\t %c\t 第 %d 名\n", ArrStu[i].name, ArrStu[i].stu_num, ArrStu[i].marks.scores, ArrStu[i].marks.grade,  ArrStu[i].marks.order);
    }
    for (int i = 0; i < 5; i++) {
        printf("成绩等级为 %c 的有 %d 位同学\n", 65 + i, count_grade[i]);
    }
    printf("平均成绩为: %.2lf", avg);
    return 0;
}

double Static (Stu* ArrStu, int* count_grade) {
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        printf("%d\n", (ArrStu + i)->marks.scores);
        if ((*(ArrStu + i)).marks.scores >= 90) {
            (*(ArrStu + i)).marks.grade = 'A';
            (*count_grade)++;
        }
        else if ((*(ArrStu + i)).marks.scores >= 80 && (*(ArrStu + i)).marks.scores < 90) {
            (*(ArrStu + i)).marks.grade = 'B';
            (*(count_grade + 1))++;
        }
        else if ((*(ArrStu + i)).marks.scores >= 70 && (*(ArrStu + i)).marks.scores < 80) {
            (*(ArrStu + i)).marks.grade = 'C';
            (*(count_grade + 2))++;
        }
        else if ((*(ArrStu + i)).marks.scores >= 60 && (*(ArrStu + i)).marks.scores < 70) {
            (*(ArrStu + i)).marks.grade = 'D';
            (*(count_grade + 3))++;
        }
        else if ((*(ArrStu + i)).marks.scores >= 0 && (*(ArrStu + i)).marks.scores < 60) {
            (*(ArrStu + i)).marks.grade = 'E';
            (*(count_grade + 4))++;
        }
        sum += (*(ArrStu + i)).marks.scores;
    }
    //排序求学生成绩名次
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if ((*(ArrStu + i)).marks.scores < (*(ArrStu + i)).marks.scores) {
                Stu temp = *(ArrStu + i);
                *(ArrStu + i) = *(ArrStu + j);
                *(ArrStu + j) = temp;
            }
        }
        (*(ArrStu + i)).marks.order = i + 1;
    }
    //根据原始排序还原顺序
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if ((*(ArrStu + i)).input_order > (*(ArrStu + i)).input_order) {
                Stu temp = *(ArrStu + i);
                *(ArrStu + i) = *(ArrStu + j);
                *(ArrStu + j) = temp;
            }
        }
    }
    return (sum / 10);
}