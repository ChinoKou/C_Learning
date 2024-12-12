#include <stdio.h>
#include <stdlib.h>

void getx(double(*A)[3], double* x, double* b, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
//      for (k = i + 1; k < n; k++) {
//          if (abs(A[i][i]) < abs(A[k][i])) {
//              for (j = 0; j < n; j++) {
//                  double temp = A[i][j];
//                  A[i][j] = A[k][j];
//                  A[k][j] = temp;
//              }
//              double temp = b[i];
//              b[i] = b[k];
//              b[k] = temp;
//          }
//      }
        for (k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main() {
    int n = 3;
    double PI = 3.14;
    double A[3][3] = {
       {3,  4, -2},
       {2, -1,  3},
       {1,  2,  1}
    };
    double b[] = {1, 4, 7};
    double x[n];
    getx(A, x, b, n);
    for (int i = 0; i < n; i++) {
        printf("X%d = %.2lf\n", i + 1, x[i]);
    }
    return 0;
}