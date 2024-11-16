#include <stdio.h>

typedef struct {
    char name[100];
    char stu_num[10];
    struct mark marks;
} Stu;

struct mark{
    char grade;
    int order;
    double scores;
};

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
    for (int i = 0; i < 10; i++) {
        
    }
    printf("\n学生成绩排序如下: \n名次\t 姓名\t 学号\t 成绩\t\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t %s\t %s\t %.2lf\t\n", i + 1, ArrStu[i].name, ArrStu[i].stu_num, ArrStu[i].marks);
    }
    return (sum / 10);
}