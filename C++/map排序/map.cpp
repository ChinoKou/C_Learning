#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;
    for (int i = 0; i < 10; i++){
        cin >> m[i];
    }
    for(auto& item : m) {
        cout << item.second << endl;
    }
}