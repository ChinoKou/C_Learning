#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int, greater<int>> m;
    int x;
    for (int i = 0; i < 10; i++){
        cin >> x;
        m[x] = x;
    }
    cout << "排序后" << endl;
    for(auto& item : m) {
        cout << item.second << endl;
    }
}