#include <iostream>
#define MAXSIZE 100
typedef int DataType;
#include "SeqList.h"
using namespace std;

int main(){
    SeqList mylist;
    int i, x;
    ListInitiate(&mylist);
    for (int i = 0; i < 10; i++){
        ListInsert(&mylist, i, i + 1);
    }
    ListDelete(&mylist, 4, &x);
    for (int i = 0; i < ListLength(mylist); i++){
        ListGet(mylist, i, &x);
        cout << x << endl;
    }
}