#include <iostream>
#include "SeqList.h"
using namespace std;


int main(){
    SeqList List;
    ListInitiate(&List);
    ListInsert(&List, 0, 1);
    ListInsert(&List, 1, 2);
    ListInsert(&List, 2, 3);
    ListInsert(&List, 1, 66);
    for (int i = 0; i < List.Size; i++){
        cout << List.List[i] << endl;
    }
    int x;
    ListGet(List, 0, &x);
    cout << x << endl;
    cout << ListLength(List) << endl;
    int del_x;
    ListDelete(&List, 0, &del_x);
    cout << del_x << endl;
    cout << endl;
    for (int i = 0; i < List.Size; i++){
        cout << List.List[i] << endl;
    }
}