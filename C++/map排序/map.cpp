#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;
    int x;
    for (int i = 0; i < 10; i++){
        cin >> x;
        m[x] = x;
    }
    for(auto& item : m) {
        cout << item.second << endl;
    }
}