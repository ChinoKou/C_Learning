#include <stdio.h>
#include <stdlib.h>

typedef struct EmployeeInformation{
    char name[100];
    double money;
    struct EmployeeInformation *next;
}Info;

void max_list(Info* head);

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
    max_list(list);
    temp = list;
    while(temp != NULL){
        list = temp->next;
        free(temp);
        temp = list;
    }
}

void max_list(Info* head){
    double max = head->money;
    for (Info *temp = head; temp != NULL; temp = temp->next){
        if (max < temp->money) max = temp->money;
    }
    for (Info *temp = head; temp != NULL; temp = temp->next){
        if (max == temp->money) printf("基本工资最高的是: %s, 工资为: %lf\n", temp->name, temp->money);
    }
}