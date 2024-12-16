#include <iostream>
using namespace std;

void getx(double(*A)[3], double* b);

int main() {
    double A[3][3], b[3];
    cout << "输入矩阵: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    cout << "输入b:" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    getx(A, b);
    return 0;
}

void getx(double(*A)[3], double* b) {
    if (!A[0][0]) {
        
    }
}