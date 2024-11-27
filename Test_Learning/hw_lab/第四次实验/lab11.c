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
    int count = 0;
    Date isFish = {1900, 1, 1};
    if (count % 5 >= 0 && count % 5 <= 2) {
        return 1;
    }
    else {
        return 0;
    }
}