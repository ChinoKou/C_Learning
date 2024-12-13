#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getx(double(*A)[3], double* b, double* origin);

int main() {
    int n = 3;
    double PI = 3.14;
    double OT = 1 / 3;
    double A[3][3] = {
        {0,      3.14, 3.14},
        {-3.14, -3.14, 0},
        {2.094,  0,    2.094}
    };
    double b[3] = {6.28, 6.28, 6.28};
    double origin[3] = {0, 3.14, 0};
    int k[3];
    for (k[1] = -5; k[1] <= 5; k[1]++) {
        for (k[2] = -5; k[2] <= 5; k[2]++) {
            for (k[3] = -5; k[3] <= 5; k[3]++) {
                double temp_b[3];
                for (int i = 0; i < 3; i++) {
                    temp_b[i] = b[i];
                    temp_b[i] *= k[i];
                }
                getx(A, temp_b, origin);
                for (int i = 0; i < 3; i++) {
                    printf("K%d = %d\n", i + 1, k[i]);
                }
            }
        }
    }
    double x[n];
    return 0;
}

int getx(double(*A)[3], double* b, double* origin) {
    double copy_A[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copy_A[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int k = i + 1; k < 3; k++) {
            if (fabs(A[i][i]) < fabs(A[k][i])) {
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
            origin[k] -= factor * origin[i];
        }
    }
    double x[3];
    for (int i = 3 - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < 3; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return x[1] == floor(x[1]) && x[2] == floor(x[2]) && x[3] == floor(x[3]);
}