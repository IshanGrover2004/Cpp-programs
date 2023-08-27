#include <stdio.h>

void transpose(int mat[20][20], int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int isSymmetric(int mat[20][20], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (mat[i][j] != mat[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int mat[20][20], size, i, j;

    printf("Enter size of matrix: ");
    scanf("%d", &size);

    printf("Enter elements of matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    transpose(mat, size);

    printf("Transpose Matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    if (isSymmetric(mat, size))
        printf("matrix is symmetric\n");
    else 
        printf("matrix is not symmetric.\n");
    

    return 0;
}
