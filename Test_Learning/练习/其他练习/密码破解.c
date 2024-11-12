#include <stdio.h>
#include <string.h>

int is_valid (char* password);
int guess_password (char* password, int len);
int is_password (char* password, char* guess);

int main () {
    char password[1000];
    printf("密码: ");
    scanf("%s", &password);
    while (!is_valid(password)) {
        printf("请再次输入！\n密码: ");
        scanf("%s", &password);
    }
    int len = strlen(password);
    guess_password(password, len);
    return 0;
}

int is_valid (char* password) {
    int count[3] = {0, 0, 0};
    for (int i = 0; *(password + i) != '\0'; i++) {
        if (*(password + i) > '0' && *(password + i) < '9') {
            count[0] = 1;
        }
        else if (*(password + i) > 'a' && *(password + i) < 'z') {
            count[1] = 1;
        }
        else if (*(password + i) > 'A' && *(password + i) < 'Z') {
            count[2] = 1;
        }
    }
    return (count[0] && count[1] && count[2]);
}

int guess_password (char* password, int len) {
    char key[62] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char guess[1000];
    int j = 0, digit = len, digit_j = 0;

    guess[len + 1] = '\0';

    while (!is_password(password, guess)) {

        //密码不对，继续
        if (digit_j == 61) {
            digit -= 1;
            digit_j = 0;
        }

        //生成该串猜的密码
        for (int i = 0; i < len; i++) {
            if (i <= (digit - 1)) {
                guess[i] = key[j];
            }
            else if (i == (digit - 1)) {
                guess[i] = key[digit_j];
            }
        }

        //判断猜对与否
        if (is_password(password, guess)) {
            printf("猜对了, 密码为: %s", guess);
            return 1;
        }

        digit_j++;
    }
    return 0;
}

int is_password (char* password, char* guess) {
    for (int i = 0; *(password + i) != '\0'; i++) {
        if (*(password + i) != *(guess + i)) {
            return 0;
        }
    }
    return 1;
}