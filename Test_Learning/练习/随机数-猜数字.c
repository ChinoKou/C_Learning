#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int guess(int x);

int main () {
    int x;
    while (1) {
        printf("请输入你所猜的数字：（20 - 50）\n");
        scanf("%d", &x);
        int guess_num = guess(x);
        if (guess_num) {
            goto out;
        }
    }
    out:
    return 0;
}

int guess(int x) {
    int guess;
    srand(time(NULL));
    guess = rand() % 31 + 20;
    if (x == guess) {
        printf("猜对了！\n");
        printf("数字是: %d", guess);
        printf("\n");
        return 1;
    }
    else {
        printf("猜错了！\n");
        printf("真正的数字是: %d", guess);
        printf("\n");
        return 0;
    }
}