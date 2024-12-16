#include <stdio.h>
#include <math.h>

int getx(double(*A)[3], double* x, double* b);

int main() {
    double origin[3], A[3][3], x[3], b[3] = {6.28, 6.28, 6.28}, temp_b[3];
    int k[3], k_start[3], k_stop[3];
    int mode[3][2], rotation_direction[3], rotation_mode[3][3] = {0}, origin_position[3];
    char* floor[3] = {"外层", "中层", "内层"};
    printf("输入外层 中层 内层的初始位置 (0 ~ 5) :");
    scanf("%d %d %d", &origin_position[0], &origin_position[1], &origin_position[2]);
    printf("输入外层 中层 内层的旋转方向 (0 - 逆时针 1 - 顺时针) :");
    scanf("%d %d %d", &rotation_direction[0], &rotation_direction[1], &rotation_direction[2]);
    printf("无 - 0 外层 - 1 中层 - 2 内层 - 3\n");
    for (int i = 1; i <= 3; i++) {
        printf("第 %d 种模式:", i);
        scanf("%d %d", &mode[i - 1][0], &mode[i - 1][1]);
        for (int j = 1; j <= 2; j++) {
            if (mode[i - 1][j - 1]) {
                printf("输入 %s 的旋转模式 (旋转占比[1 ~ 6]) : ", floor[mode[i - 1][j - 1] - 1]);
                scanf("%d", &rotation_mode[mode[i - 1][j - 1] - 1][i - 1]);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        origin[i] = (double)origin_position[i] / 3 * 3.14;
        for (int j = 0; j < 3; j++) {
            A[i][j] = (double)rotation_mode[i][j] / 3 * 3.14;
        }
        if (rotation_direction[i]) {
            k_start[i] = 1;
            k_stop[i] = 5;
        }
        else if (!(rotation_direction[i])) {
            k_start[i] = -5;
            k_stop[i] = -1;
        }
    }
    for (k[0] = k_start[0]; k[0] <= k_stop[0]; k[0]++) {
        for (k[1] = k_start[1]; k[1] <= k_stop[1]; k[1]++) {
            for (k[2] = k_start[2]; k[2] <= k_stop[2]; k[2]++) {
                for (int i = 0; i < 3; i++) {
                    temp_b[i] = b[i];
                    temp_b[i] *= k[i];
                    temp_b[i] -= origin[i];
                }
                if (getx(A, x, temp_b)) {
                    printf("K1 = %d, K2 = %d, K3 = %d\n", k[0], k[1], k[2]);
                    for (int i = 0; i < 3; i++) {
                        printf("X%d = %.0lf\n", i + 1, x[i]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}

int getx(double(*origin_A)[3], double* x, double* b) {
    double A[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = origin_A[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int k = i + 1; k < 3; k++) {
            if (abs(A[i][i]) < abs(A[k][i])) {
                for (int j = 0; j < 3; j++) {
                    double temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
                double temp = b[i];
                b[i] = b[k];
                b[k] = temp;
            }
        }
        for (int k = i + 1; k < 3; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }
    for (int i = 3 - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < 3; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return fabs(x[1] - round(x[1])) <= 0.2 && fabs(x[2] - round(x[2])) <= 0.2 && fabs(x[3] - round(x[3])) <= 0.2;
}