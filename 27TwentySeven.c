//Sparse Matrix
#include <stdio.h>
#define ROWS 4
#define COLS 4
int main() {
    int matrix[ROWS][COLS] = {
        {0, 0, 3, 0},
        {5, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 2, 0, 6}
    };
    int nonZeroCount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    int sparse[nonZeroCount + 1][3];
    sparse[0][0] = ROWS;
    sparse[0][1] = COLS;
    sparse[0][2] = nonZeroCount;
    int k = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("Sparse Matrix (3-Tuple Representation):\n");
    printf("Row\tCol\tValue\n");
    printf("---------------------\n");
    for (int i = 0; i <= nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    return 0;
}