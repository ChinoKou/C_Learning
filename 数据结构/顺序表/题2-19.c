#include <stdio.h>
#define MAXSIZE 100
typedef int DataType;
#include "C_LinkedList.h"
#include <malloc.h>

int ListDeleteMore(LinkedList* List, DataType x);
void ListInsert(LinkedList* List, int i, DataType x);
void ListDelete(LinkedList* List, DataType x);

int main(){
    LinkedList *head = NULL, *tail = NULL, *tmp = NULL;
    for (int i = 0; i < 10; i++){
        tmp = (LinkedList*)malloc(sizeof(LinkedList));
        tmp->data = i + 1;
        tmp->next = NULL;
        if (head == NULL || tail == NULL) head = tail = tmp;
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }
    //cout << "删除 " << ListDeleteMore(head, 5) << " 个元素" << endl;
    ListInsert(head, 5, 15);
    printf("在索引 5 处插入 15\n");
    for (tmp = head; tmp != NULL; tmp = tmp->next){
        printf("%d ", tmp->data);
    }
    int x = 15;
    printf("\n删除元素 %d\n", x);
    ListDelete(head, x);
    for (tmp = head; tmp != NULL; tmp = tmp->next){
        printf("%d ", tmp->data);
    }
}

int ListDeleteMore(LinkedList* List, DataType x){
    int count = 0;
    for (LinkedList *tmp = List, *last = List; tmp != NULL; tmp = tmp->next){
        if (tmp->data == x){
            last->next = tmp->next;
            count++;
            free(tmp);
            LinkedList *tmp = last;
        }
        else last = tmp;
    }
    return count;
}

void ListInsert(LinkedList* List, int i, DataType x){
    for (int j = 1; j < i; j++){
        List = List->next;
    }
    LinkedList *insert = (LinkedList*)malloc(sizeof(LinkedList));
    insert->data = x;
    insert->next = List->next;
    List->next = insert;
}

void ListDelete(LinkedList* List, DataType x){
    for (LinkedList *tmp = List, *last = List; tmp != NULL; tmp = tmp->next){
        if (tmp->data == x){
            last->next = tmp->next;
            free(tmp);
            return;
        }
        else last = tmp;
    }
}