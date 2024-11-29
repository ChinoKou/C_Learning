#include <iostream>
using namespace std;

struct room {
    int num;
    char name[100];
    room* next;
};

int main() {
    room *head = NULL, *tmp = NULL, *tail = NULL;
    tmp = new room({101, "a", NULL});
    head = tail = tmp;
    tmp = new room({102, "b", NULL});
    (*tail).next = tmp;
    tail = tmp;
    tmp = new room({103, "c", NULL});
    (*tail).next = tmp;
    tail = tmp;
    while(head != ) {

    }
    return 0;
}