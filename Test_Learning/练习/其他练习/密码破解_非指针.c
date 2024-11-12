#include <stdio.h>
#include <string.h>

int main () {
    char password[6], guess[6], arr[5];
    int is_valid[3] = {0, 0, 0}, len;
    while (!is_valid[0] || !is_valid[1] || !is_valid[2]) {
        is_valid[0] = is_valid[1] = is_valid[2] = 0;
        printf("请输入密码: ");
        scanf("%s", &password);
        len = strlen(password);
        for (int i = 0; i < len; i++) {
            if (password[i] >= '0' && password[i] <= '9') {
                is_valid[0] = 1;
            }
            else if (password[i] >= 'a' && password[i] <= 'z') {
                is_valid[1] = 1;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z') {
                is_valid[2] = 1;
            }
        }
        if (!is_valid[0] || !is_valid[1] || !is_valid[2]) {
            printf("密码输入错误, 请重新输入!\n");
        }
    }
    for (arr[0] = 33; arr[0] <= 126; arr[0]++) {
        for (arr[1] = 33; arr[1] <= 126; arr[1]++) {
            for (arr[2] = 33; arr[2] <= 126; arr[2]++) {
                for (arr[3] = 33; arr[3] <= 126; arr[3]++) {
                    if (len < 4) arr[3] = 126;
                    for (arr[4] = 33; arr[4] <= 126; arr[4]++) {
                        if (len < 5) arr[4] = 126;
                        guess[0] = arr[0];
                        guess[1] = arr[1];
                        guess[2] = arr[2];
                        guess[3] = arr[3];
                        guess[4] = arr[4];
                        guess[5] = '\0';
                        for (int i = 4; i > len - 1; i--) {
                            guess[i] = '\0';
                        }
                        printf("%s\n", guess);
                        if (!strcmp(guess, password)) {
                            printf("猜到了!\n密码为: %s", guess);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}