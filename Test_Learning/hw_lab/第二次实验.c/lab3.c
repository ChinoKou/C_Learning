#include <stdio.h>

void main () {
    int n, sum = 0, grade_a = 0, grade_b = 0, grade_c = 0, grade_d = 0, grade_e = 0;
    printf("请输入学生总人数<正整数>:");
    scanf("%d", &n);
    int arr[1000] = {'\0'};
    printf("请输入 %d 个学生成绩<0 - 100 间整数>:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
        sum += arr[i];
        if (arr[i] >= 90 && arr[i] <= 100) {
            grade_a += 1;
        }
        else if (arr[i] >= 80 && arr[i] < 90) {
            grade_b += 1;
        }
        else if (arr[i] >= 70 && arr[i] < 80) {
            grade_c += 1;
        }
        else if (arr[i] >= 60 && arr[i] < 70) {
            grade_d += 1;
        }
        else if (arr[i] >= 0 && arr[i] < 60) {
            grade_e += 1;
        }
    }
    double avg = (double)sum / n;
    printf("平均分 = %lf\n", avg);
    printf("A级人数 = %d, B级人数 = %d, C级人数 = %d, D级人数 = %d, E级人数 = %d", grade_a, grade_b, grade_c, grade_d, grade_e);
}