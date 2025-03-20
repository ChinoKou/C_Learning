#include <stdio.h>
#include <stdlib.h>

typedef struct StudentInformation{
    double mark;
    struct StudentInformation *next;
}Info;

void list_print  (Info *head);
void list_sort   (Info *head);
Info *list_merge (Info *list1, Info *list2);
Info *list_create();

int main(){
    printf("输入第一条链表的学生成绩:\n");
    Info *list1 = list_create();
    printf("\n输入第二条链表的学生成绩:\n");
    Info *list2 = list_create();

    printf("第一条升序单向链表中学生成绩如下:\n");
    list_print(list1);
    printf("第二条升序单向链表中学生成绩如下:\n");
    list_print(list2);

    Info *list3 = list_merge(list1, list2);
    printf("合并链表后:\n");
    list_print(list3);

    Info *temp = list3;
    while(temp != NULL){
        list3 = temp->next;
        free(temp);
        temp = list3;
    }
}

void list_print(Info *head){
    for (Info *temp = head; temp != NULL; temp = temp->next){
        printf("%.1lf ", temp->mark);
    }
    printf("\n\n");
}

void list_sort(Info *head){
    for (Info *temp_1 = head; temp_1 != NULL; temp_1 = temp_1->next){
        for (Info *temp_2 = temp_1; temp_2 != NULL; temp_2 = temp_2->next){
            if (temp_1->mark > temp_2->mark){
                double temp = temp_1->mark;
                temp_1->mark = temp_2->mark;
                temp_2->mark = temp;
            }
        }
    }
}

Info *list_create(){
    Info *list = NULL, *temp = NULL, *tail = NULL;
    for (int i = 1; ; i++){
        temp = (Info*)malloc(sizeof(Info));
        temp->next = NULL;
        printf("请输入第 %d 位学生的成绩: ", i);
        scanf("%lf", &(temp->mark));
        if (temp->mark < 0){
            free(temp);
            break;
        }
        if (list == NULL) list = temp;
        else tail->next = temp;
        tail = temp;
    }
    list_sort(list);
    return list;
}

Info *list_merge(Info *list1, Info *list2){
    Info *temp;
    for (temp = list1; temp->next != NULL; temp = temp->next);
    temp->next = list2;
    list_sort(list1);
    return list1;
}