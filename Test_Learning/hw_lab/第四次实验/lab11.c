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
    while (isFish.year != Fish.year && isFish.month != Fish.month && isFish.day != Fish.day) {
        if (isFish.day == 30) {
            isFish.day = 1;
            isFish.month += 1;
        }
        isFish.day += 1;
    }
}