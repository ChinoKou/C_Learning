#include <iostream>
#define MAXSIZE 100
typedef int DataType;
#include "SeqList.h"
using namespace std;

int ListFind(SeqList L, DataType x, int i);
void incremental_list_insert(SeqList* L, DataType x);

int main(){
    SeqList mylist;
    ListInitiate(&mylist);
    for (int i = 0; i < 5; i++){
        ListInsert(&mylist, i, i + 1);
    }
    cout << "ListLength:" << ListLength(mylist) << endl;
    cout << "LIST::" << endl;
    int x;
    for (int i = 0; i < 5; i++){
        ListGet(mylist, i, &x);
        cout << x << endl;
    }
    cout << "查找元素：3" << endl;
    cout << "位于索引" << ListFind(mylist, 3, 1);
    incremental_list_insert(&mylist, 3.5);
    cout << "LIST::" << endl;
    for (int i = 0; i < 5; i++){
        ListGet(mylist, i, &x);
        cout << x << endl;
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
    for (int j = (*L).Size; j > i; j--){
        (*L).List[j] = (*L).List[j - 1];
    }
    (*L).List[i] = x;
    (*L).Size += 1;
}