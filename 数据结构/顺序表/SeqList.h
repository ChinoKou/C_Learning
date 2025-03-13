#ifndef MAXSIZE
#define MAXSIZE 100
#endif
#ifndef DataType
#define DataType int
#endif
using namespace std;

typedef struct{
    DataType List[MAXSIZE];
    int Size;
}SeqList;

void ListInitiate(SeqList* L){
    (*L).Size = 0;
}

int ListLength(SeqList L){
    return L.Size;
}

int ListInsert(SeqList* L, int i, DataType x){
    if ((*L).Size >= MAXSIZE){
        cout << "顺序表已满" << endl;
        return 0;
    }
    else if (i < 0 || i > (*L).Size){
        cout << "参数不合法" << endl;
        return 0;
    }
    else{
        for (int j = (*L).Size; j > i; j--){
            (*L).List[j] = (*L).List[j - 1];
        }
        (*L).List[i] = x;
        (*L).Size += 1;
        return 1;
    }
}

int ListDelete(SeqList* L, int i, DataType* x){
    if ((*L).Size <= 0){
        cout << "当前无数据可删" << endl;
        return 0;
    }
    else if (i < 0 || i >= (*L).Size){
        cout << "参数不合法" << endl;
        return 0;
    }
    else{
        *x = (*L).List[i];
        for (int j = i; j < (*L).Size - 1; j++){
            (*L).List[j] = (*L).List[j + 1];
        }
        (*L).Size -= 1;
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType* x){
    if (i < 0 || i >= L.Size){
        cout << "参数不合法" << endl;
        return 0;
    }
    else{
        *x = L.List[i];
        return 1;
    }
}