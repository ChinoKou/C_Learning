#include <stdio.h>
#include <math.h>

int getx(double(*A)[3], double*x, double* b);

int main() {
    int n = 3;
    double A[3][3];
    double origin[3];
    double origin_position[3];
    int k_start[3];
    int k_stop[3];
    int rotate_mode[3][2];
    char floor[3] = {"外层", "中层", "内层"};
    printf("输入外层 中层 内层的初始位置 (0 ~ 5) :");
    scanf("%d %d %d", &origin_position[0], &origin_position[1], &origin_position[2]);
    printf("外层 - 1 中层 - 2 内层 - 3\n");
    for (int i = 1; i <= 3; i++) {
        printf("第 %d 种模式:", i);
        scanf("%d %d", &rotate_mode[i - 1][0], &rotate_mode[i - 1][1]);
        for (int j = 1; j <= 2; j++) {
            printf("输入 %c 的旋转模式 (int - 顺[1]逆[2]时针 int int - 旋转占比[1 ~ 6]) : ", floor[rotate_mode[i - 1][j - 1] - 1]);
            scanf("");
        }
    }
    A[0][0] = 0 ;            A[0][1] = 3.14;     A[0][2] = 3.14;
    A[1][0] = -3.14;        A[1][1] = -3.14;    A[1][2] = 0;
    A[2][0] = 2 * 3.14 / 3; A[2][1] = 0;        A[2][2] =  2 * 3.14 / 3;
    origin[0] = (double)origin_position[0] / 6 * 3.14;
    origin[1] = (double)origin_position[1] / 6 * 3.14;
    origin[2] = (double)origin_position[2] / 6 * 3.14;
    double b[3] = {6.28, 6.28, 6.28};
    double temp_b[3];
    int k[3];
    double x[3];
    for (k[0] = 1; k[0] <= 5; k[0]++) {
        for (k[1] = -5; k[1] <= -1; k[1]++) {
            for (k[2] = 1; k[2] <= 5; k[2]++) {
                for (int i = 0; i < 3; i++) {
                    temp_b[i] = b[i];
                    temp_b[i] *= k[i];
                    temp_b[i] -= origin[i];
                }
                if (getx(A, x, temp_b)) {
                    printf("K1 = %d, K2 = %d, K3 = %d\n", k[0], k[1], k[2]);
                    for (int i = 0; i < 3; i++) {
                        printf("X%d = %.1lf\n", i + 1, x[i]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}

int getx(double(*A)[3], double*x, double* b) {
    double copy_A[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copy_A[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int k = i + 1; k < 3; k++) {
            if (abs(copy_A[i][i]) < abs(copy_A[k][i])) {
                for (int j = 0; j < 3; j++) {
                    double temp = copy_A[i][j];
                    copy_A[i][j] = copy_A[k][j];
                    copy_A[k][j] = temp;
                }
                double temp = b[i];
                b[i] = b[k];
                b[k] = temp;
            }
        }
        for (int k = i + 1; k < 3; k++) {
            double factor = copy_A[k][i] / copy_A[i][i];
            for (int j = i; j < 3; j++) {
                copy_A[k][j] -= factor * copy_A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }
    for (int i = 3 - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < 3; j++) {
            x[i] -= copy_A[i][j] * x[j];
        }
        x[i] /= copy_A[i][i];
    }
    return  fabs(x[1] - round(x[1])) <= 0.2 && fabs(x[2] - round(x[2])) <= 0.2 && fabs(x[3] - round(x[3])) <= 0.2;
}