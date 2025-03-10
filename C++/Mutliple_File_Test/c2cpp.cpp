#include "fish.h"

int main () {
    Date Fish;
    cout << "请输入日期(年 月 日): ";
    cin >> Fish.year, cin >> Fish.month, cin >> Fish.day;
    cout << "若一个月只有30天" << endl;
    if (FishNet(Fish)) {
        cout << "则此人这天为打鱼";
    }
    else {
        cout << "则此人这天为晒网";
    }
    return 0;
}