#include <stdio.h>

void matrixMultiply(int mat1[20][20], int mat2[20][20], int res[20][20], int rows1, int cols1, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            res[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[20][20], mat2[20][20], res[20][20];
    

    return 0;
}
