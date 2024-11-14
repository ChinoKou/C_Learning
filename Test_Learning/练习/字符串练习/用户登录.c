#include <stdio.h>
#include <string.h>

int main () {
    char user[5] = "user", password[10] = "password", input_user[1000], input_password[1000];
    for (int i = 1; i <= 3; i++) {
        printf("用户名: ");
        scanf("%s", input_user);
        printf("密码: ");
        scanf("%s", input_password);
        if (!strcmp(user, input_user) && !strcmp(password, input_password)) {
            printf("密码正确! ");
            break;
        }
        else {
            if (i == 3) {
                printf("登录失败! ");
                break;
            }
            printf("用户名或密码输入错误, 请重新输入! \n");
            printf("你还有 %d 次机会! \n", 3 - i);
        }
    }
    return 0;
}