#include <stdio.h>
#include <stdlib.h>

typedef struct EmployeeInformation{
    char name[100];
    double money;
    struct EmployeeInformation *next;
}Info;

void del_list(Info *head, double del);

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

    double del, i = 1;
    printf("请输入给定基本工资: ");
    scanf("%lf", &del);
    del_list(list, del);
    for (Info *temp = list; temp != NULL; temp = temp->next, i++){
        printf("第 %.0lf 位的职工姓名: %s, 基本工资: %.1lf\n", i, temp->name, temp->money);
    }

    temp = list;
    while(temp != NULL){
        list = temp->next;
        free(temp);
        temp = list;
    }
}

void del_list(Info *head, double del){
    for (Info *temp = head, *last = head; temp != NULL; temp = temp->next){
        if (temp->money == del){
            last->next = temp->next;
            free(temp);
            temp = last;
        }
        else last = temp;
    }
}