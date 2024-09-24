#include <stdio.h>

int main () {
    int bei_chu_shu, chu_shu;
    scanf("%d %d", &bei_chu_shu, &chu_shu);
    int i = chu_shu, shang = 1;
    while (i + chu_shu <= bei_chu_shu) {
        i += chu_shu;
        shang += 1;
    }
    printf("商为：%d, 余数为: %d", shang, (bei_chu_shu - i));
    return 0;
}
