#include <stdio.h>

typedef struct {
    int year, month, day;
} Date;

int FishNet (Date Fish);


int main () {
    Date Fish;
    printf("请输入日期(年 月 日): ");
    scanf("%d %d %d", &Fish.year, &Fish.month, &Fish.day);
    if (FishNet(Fish)) {
        printf("此人这天为打鱼");
    }
    else {
        printf("此人这天为晒网");
    }
    return 0;
}

int FishNet (Date Fish) {
    Date isFish = {1900, 1, 1};
    int year = Fish.year - isFish.year;
    int month = Fish.month - isFish.month;
    int day = Fish.day - isFish.day;
    int count = year * 12 * 30 + month * 30 + day;
    if (count % 5 >= 0 && count % 5 <= 2) {
        return 1;
    }
    else {
        return 0;
    }
}