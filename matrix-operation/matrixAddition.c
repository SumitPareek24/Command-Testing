#include <stdio.h>

void takeInputOfMatrix(char * matrixNo, int row, int column, int (*matrix)[column]) {
    printf("Enter elements of %s matrix\n", matrixNo);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void takeInputOfDimension(int * rows, int * column) {
    scanf("%d %d", rows, column);
}

void performOperation(int rows, int column, int (*firstMatrix)[column], int (*secondMatrix)[column], int (*resultMatrix)[column]) {
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < column; j++) {
            resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

void printMatrix(int rows, int column, int (* resultMatrix)[column]) { 
    printf("Addition of 2 matrices:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < column; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int rows = 0, column = 0;
    printf("Enter rows and columns: ");
    takeInputOfDimension(&rows, &column);

    int firstMatrix[rows][column], secondMatrix[rows][column], resultMatrix[rows][column];

    takeInputOfMatrix("first", rows, column, firstMatrix);
    takeInputOfMatrix("second", rows, column, secondMatrix);

    performOperation(rows, column, firstMatrix, secondMatrix, resultMatrix);

    printMatrix(rows, column, resultMatrix);

    return 0;
}