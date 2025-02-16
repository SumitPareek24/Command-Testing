/*

[1 2 3]   [4 7 2]
[4 5 6] x [9 1 4] 
[7 8 9]   [8 3 5]

[1 2 3]   [4 7 2 1]
[4 5 6] x [9 1 4 8] 
[7 8 9]   [9 8 1 3]
[1 7 3]   
 4 x 3      3 x 4

4 3
3 4
1 2 3 4 5 6 7 8 9 10 11 12
9 8 7 6 5 4 3 2 1 11 12 10

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void takeInputDimension(int* row, int* column) {
    printf("row: ");
    scanf("%d", row);
    printf("column: ");
    scanf("%d", column);
}

void takeInputMatrix(int row, int column, int (* matrix)[column]) {
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }
}

void multiplyMatrix(int firstMatrixRow, int firstMatrixColumn, int secondMatrixRow, int secondMatrixColumn, 
                    int (* matrix1)[firstMatrixColumn], int (* matrix2)[secondMatrixColumn],
                        int (* resultantMatrix)[secondMatrixColumn]) {
    for (int rowIndex = 0; rowIndex < firstMatrixRow; rowIndex++)
    {
        for (int colIndex = 0; colIndex < secondMatrixColumn; colIndex++)
        {
            int sum = 0;    
            for (int commonIndex = 0; commonIndex < secondMatrixRow; commonIndex++)
            {
                sum = sum + matrix1[rowIndex][commonIndex] * matrix2[commonIndex][colIndex];
            }
            resultantMatrix[rowIndex][colIndex] = sum;
        }
    }
}

void printMatrix(int row, int column, int (* matrix)[column]) {
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");        
    }
}

int main() {

    int row1, row2;
    int column1, column2;

    printf("Enter dimension of matrix 1:\n");
    takeInputDimension(&row1, &column1);

    printf("Enter dimension of matrix 2:\n");
    takeInputDimension(&row2, &column2);

    if(column1 != row2) {
        printf("Column of 1st matrix should be equal to the row of 2nd matrix\n");
        return 0;
    }

    int matrix1[row1][column1];
    int matrix2[row2][column2];

    printf("Enter elements of 1st matrix\n");
    takeInputMatrix(row1, column1, matrix1);

    printf("Enter elements of 2nd matrix\n");
    takeInputMatrix(row2, column2, matrix2);

    int resultantMatrix[row1][column2];

    multiplyMatrix(row1, column1, row2, column2, matrix1, matrix2, resultantMatrix);
    printf("resultant matrix\n");
    printMatrix(row1, column2, resultantMatrix);

    return 0;
}