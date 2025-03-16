#include <stdio.h>
#define MAXSIZE 100
typedef int DataType;
#include "SeqList.h"

int ListFind(SeqList L, DataType x, int i);
void incremental_list_insert(SeqList* L, DataType x);

int main(){
    SeqList mylist;
    ListInitiate(&mylist);
    for (int i = 0; i < 5; i++){
        ListInsert(&mylist, i, i + 1);
    }
    printf("ListLength: %d \n", ListLength(mylist));
    printf("LIST::\n");
    int x;
    for (int i = 0; i < 5; i++){
        ListGet(mylist, i, &x);
        printf("%d\n", x);
    }
    printf("查找元素：3\n");
    printf("位于索引%d", ListFind(mylist, 3, 1));
    incremental_list_insert(&mylist, 3.5);
    printf("LIST::\n");
    for (int i = 0; i < 5; i++){
        ListGet(mylist, i, &x);
        printf("%d\n", x);
    }
}

int ListFind(SeqList L, DataType x, int i){
    for (; i < ListLength(L); i++){
        if (L.List[i] == x) return i;
    }
    return -1;
}

void incremental_list_insert(SeqList* L, DataType x){
    int i;
    while (L->List[i] < x) i++;
    for (int j = L->Size; j > i; j--){
        L->List[j] = L->List[j - 1];
    }
    L->List[i] = x;
    L->Size += 1;
}