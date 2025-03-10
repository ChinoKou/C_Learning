#include <iostream>
#define MAXSIZE 100
typedef int DataType;
#include "LinkedList.h"
using namespace std;

int ListDeleteMore(LinkedList* List, DataType x);
void ListInsert(LinkedList* List, int i, DataType x);

int main(){
    LinkedList *head = nullptr, *tail = nullptr, *tmp = nullptr;
    for (int i = 0; i < 10; i++){
        tmp = new LinkedList;
        tmp->data = i + 1;
        tmp->next = nullptr;
        if (head == nullptr || tail == nullptr) head = tail = tmp;
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }
    //cout << "删除 " << ListDeleteMore(head, 5) << " 个元素" << endl;
    ListInsert(head, 5, 15);
    cout << "在索引 5 处插入 15" << endl;
    for (tmp = head; tmp != nullptr; tmp = tmp->next){
        cout << tmp->data << " ";
    }
}

int ListDeleteMore(LinkedList* List, DataType x){
    int count;
    for (LinkedList *tmp = List, *last = List; tmp != nullptr; tmp = tmp->next){
        if (tmp->data == x){
            last->next = tmp->next;
            count++;
            delete tmp;
        }
        else last = tmp;
    }
    return count;
}

void ListInsert(LinkedList* List, int i, DataType x){
    LinkedList *tmp = List;
    for (int j = 0; j < i; j++){
        tmp = tmp->next;
    }
    LinkedList *tmp = new LinkedList;
    tmp->data = x;
    List->next = tmp;
    tmp->next = List->next;
}