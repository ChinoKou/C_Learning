#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

int FishNet (Date Fish);
int is_bissextile (int year);

int main () {
    Date Fish;
    printf("\n请输入日期(年 月 日): ");
    scanf("%d %d %d", &Fish.year, &Fish.month, &Fish.day);
    if (FishNet(Fish)) {
        printf("则此人这天为打鱼\n");
    }
    else {
        printf("则此人这天为晒网\n");
    }
    return 0;
}

int FishNet (Date Fish) {
    int days = Fish.day - 1;
    for (int i = 1900; i < Fish.year; i++) {
        days += 365 + is_bissextile(i);
    }
    for (int i = 1; i < Fish.month; i++) {
        if (i == 2) {
            days += 28 + is_bissextile(Fish.year);
            continue;
        }
        days += 30 + !(i == 4 || i == 6 || i == 9 || i == 11);
        /*if (i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        }
        else {
            days += 31;
        }*/
    }
    return (days % 5 >= 0 && days % 5 <= 2);
}

int is_bissextile (int year) {
    return ((!(year % 4) && (year % 100)) || !(year % 400));
}