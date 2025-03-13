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
        delete tmp;
    }
}

void ListSort(LinkedList* head){
    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            if (head->data > head->next->data){
                int tmp = head->data;
                head->data = head->next->data;
                head->next->data = tmp;
            }
        }
    }
}