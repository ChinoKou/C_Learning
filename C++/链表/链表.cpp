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
    
}