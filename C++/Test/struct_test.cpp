#include <iostream>
using namespace std;
typedef struct {
    int year, month, day;
} Data;
int main() {
    Data a = {1, 1, 1};
    cout << a.year << " " << a.month << " " << a.day << endl;
}