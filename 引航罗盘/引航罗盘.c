#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getx(double(*A)[3], double*x, double* b);

int main() {
    int n = 3;
    double A[3][3];
    A[0][0] = 0;            A[0][1] = 3.14;     A[0][2] = 3.14;
    A[1][0] = -3.14;        A[1][1] = -3.14;    A[1][2] = 0;
    A[2][0] = 2 * 3.14 / 3; A[2][1] = 0;        A[2][2] =  2 * 3.14 / 3;
    double b[3] = {6.28, 6.28, 6.28};
    double temp_b[3];
    double origin[3] = {0, 3.14, 0};
    int k[3] = {1, -1, 1};
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