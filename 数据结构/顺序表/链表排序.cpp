#include <iostream>
#define MAXSIZE 100
typedef int DataType;
#include "LinkedList.h"
using namespace std;

void ListSort(LinkedList* head);

int main(){
    LinkedList *head = nullptr, *tail = nullptr, *tmp = nullptr;
    for (int i = 0; i < 10; i++){
        tmp = new LinkedList;
        cin >> tmp->data;
        tmp->next = nullptr;
        if (head == nullptr || tail == nullptr) head = tail = tmp;
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }
    cout << "排序前：";
    for (tmp = head; tmp->next != nullptr; tmp = tmp->next){
        cout << tmp->data << " ";
    }
    cout << endl;
    ListSort(head);
    cout << endl;
    cout << "排序后：";
    for (tmp = head; tmp->next != nullptr; tmp = tmp->next){
        cout << tmp->data << " ";
    }
    for (tmp = head; tmp->next != nullptr; tmp = tmp->next){
        LinkedList* last = tmp;
        delete last;
    }
}

void ListSort(LinkedList* head){
    for (LinkedList* tmp_1 = head; tmp_1->next != nullptr; tmp_1 = tmp_1->next){
        for (LinkedList* tmp_2 = tmp_1; tmp_2->next != nullptr; tmp_2 = tmp_2->next){
            if (tmp_1->data > tmp_2->data){
                int tmp = tmp_1->data;
                tmp_1->data = tmp_2->data;
                tmp_2->data = tmp;
            }
        }
    }
}