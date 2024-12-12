#include <stdio.h>
#include <stdlib.h>

void gaussianElimination(double(*A)[3], double* b, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        // Partial pivoting
        for (k = i + 1; k < n; k++) {
            if (abs(A[i][i]) < abs(A[k][i])) {
                for (j = 0; j < n; j++) {
                    double temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
                double temp = b[i];
                b[i] = b[k];
                b[k] = temp;
            }
        }
        // Forward elimination
        for (k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    double* x = (double*)malloc(n * sizeof(double));
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    free(x);
}

int main() {
    int n = 3;
    double PI = 3.14;
    double A[3][3] = {
       {0, PI, PI},
       {-PI, -PI, 0},
       {2 / 3 * PI,  0,  2 / 3 * PI}
    };
    double b[] = {2, 2, 2};
    gaussianElimination(A, b, n);
    return 0;
}