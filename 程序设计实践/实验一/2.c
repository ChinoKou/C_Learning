#include <stdio.h>
#include <stdlib.h>

typedef struct EmployeeInformation{
    char name[100];
    double money;
    struct EmployeeInformation *next;
}Info;

void count_list(Info *head);

int main(){
    Info *list = NULL, *temp = NULL, *tail = NULL;
    for (int i = 1; ; i++){
        temp = (Info*)malloc(sizeof(Info));
        temp->next = NULL;
        printf("\n输入第 %d 位职工的基本工资: ", i);
        scanf("%lf", &(temp->money));
        if (!temp->money){
            free(temp);
            break;
        }
        printf("输入第 %d 位职工的姓名: ", i);
        scanf("%s", temp->name);
        if (list == NULL) list = temp;
        else tail->next = temp;
        tail = temp;
    }
    count_list(list);
    temp = list;
    while(temp != NULL){
        list = temp->next;
        free(temp);
        temp = list;
    }
}

void count_list(Info *head){
    double count = 0, avg, sum = 0, result = 0;
    for (Info *temp = head; temp != NULL; temp = temp->next){
        sum += temp->money;
        count += 1;
    }
    avg = sum / count;
    for (Info *temp = head; temp != NULL; temp = temp->next){
        if (temp->money > avg) result += 1;
    }
    printf("超过平均基本工资的有 %.0lf 人, 平均基本工资为: %.2lf", result, avg);
}