#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int& ra = a;
    cout << a << endl;
    cout << &a << endl;
    cout << ra << endl;
    cout << &ra << endl;
    return 0;
}