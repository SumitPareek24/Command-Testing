#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int row;
    int column;

    printf("Enter dimension of both matrices:\n");
    printf("row: ");
    scanf("%d", &row);
    printf("column: ");
    scanf("%d", &column);
    
    int matrix1[row][column];
    int matrix2[row][column];

    printf("Enter elements of 1st matrix\n");

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            scanf("%d", &matrix1[rowIndex][colIndex]);
        }
    }

    printf("Enter elements of 2nd matrix\n");

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            scanf("%d", &matrix2[rowIndex][colIndex]);
        }
    }    

    int resultantMatrix[row][column];

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            resultantMatrix[rowIndex][colIndex] = matrix1[rowIndex][colIndex] + matrix2[rowIndex][colIndex];
        }
    }

    printf("Matrix\n");

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < column; colIndex++)
        {
            printf("%d ", resultantMatrix[rowIndex][colIndex]);
        }
        printf("\n");
    }


    return 0;
}