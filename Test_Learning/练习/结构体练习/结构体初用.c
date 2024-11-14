#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[10], grade[10];
    int age;
    double height, weight;
} 学生;

int main () {
    学生 张三 = {"张三"}, 李四 = {"李四"}, 王五 = {"王五"};
    学生 arr[3] = {张三, 李四, 王五};
    for (int i = 0; i < 3; i++) {
        printf("\n请输入学生 %s 的年级: ", arr[i].name);
        scanf("%s", arr[i].grade);
        printf("请输入学生 %s 的年龄: ", arr[i].name);
        scanf("%d", &arr[i].age);
        printf("请输入学生 %s 的身高: ", arr[i].name);
        scanf("%lf", &arr[i].height);
        printf("请输入学生 %s 的体重: ", arr[i].name);
        scanf("%lf", &arr[i].weight);
    }
    for (int i = 0; i < 3; i++) {
        printf("学生的名字为: %s, 是 %s 的, 年龄: %d, 身高: %lf, 体重: %lf\n", arr[i].name, arr[i].grade, arr[i].age, arr[i].height, arr[i].weight);
    }
    return 0;
}