#include <stdio.h>

typedef struct {
    char name[100];
    char stu_num[100];
    int scores;
} Stu;

void sort (Stu* ArrStu);

int main () {
    Stu ArrStu[10];
    for (int i = 0; i < 10; i++) {
        printf("请输入第 %d 位学生的学号, 姓名和分数: ", i + 1);
        scanf("%s %s %lf", ArrStu[i].stu_num, ArrStu[i].name, &ArrStu[i].scores);
    }
    sort(ArrStu);
    for (int i = 0; i < 10; i++) {
        printf("%s\t %s\t %lf\n", ArrStu[i].name, ArrStu[i].stu_num, ArrStu[i].scores);
    }
    return 0;
}

void sort (Stu* ArrStu) {
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (ArrStu[i].scores > ArrStu[j].scores) {
                Stu temp = ArrStu[i];
                ArrStu[i] = ArrStu[j];
                ArrStu[j] = temp;
            }
        }
    }
}