#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

int FishNet (Date Fish);

int main () {
    Date Fish;
    printf("请输入日期(年 月 日): ");
    scanf("%d %d %d", &Fish.year, &Fish.month, &Fish.day);
    printf("若一个月只有30天\n");
    if (FishNet(Fish)) {
        printf("则此人这天为打鱼");
    }
    else {
        printf("则此人这天为晒网");
    }
    return 0;
}

int FishNet (Date Fish) {
    int days = Fish.day - 1;
    for (int i = 1900; i < Fish.year; i++) {
        if (!(i % 4) && (i % 100)) {
            days += 366;
        }
        else {
            days += 365;
        }
    }
    for (int i = 1; i < Fish.month; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            days += 31;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        }
        else if (!(Fish.year % 4) && (Fish.year % 100) && Fish.year != 2000) {
            days += 29;
        }
        else {
            days += 28;
        }
    }
    if (days % 5 >= 0 && days % 5 <= 2) {
        return 1;
    }
    else {
        return 0;
    }
}