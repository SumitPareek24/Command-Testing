#include <stdio.h>

void takeInputOfMatrix(char *matrixNo, int rows, int column, int (*matrix)[column])
{
    printf("Enter elements of %s matrix\n", matrixNo);
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            scanf("%d", &matrix[rowIndex][columnIndex]);
        }
    }
}

void takeInputOfDimension(int * rows, int * column)
{
    scanf("%d %d", rows, column);
}

void performOperation(int firstMatrixColumn, int secondMatrixRow, int secondMatrixColumn,
                      int (*firstMatrix)[firstMatrixColumn], int (*secondMatrix)[secondMatrixColumn],
                      int (*resultMatrix)[secondMatrixColumn])
{
    for (int rowIndex = 0; rowIndex < firstMatrixColumn; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < secondMatrixRow; columnIndex++)
        {
            int sum = 0;
            for (int commonIndex = 0; commonIndex < firstMatrixColumn; commonIndex++)
            {
                sum += firstMatrix[rowIndex][commonIndex] * secondMatrix[commonIndex][columnIndex];
            }
            resultMatrix[rowIndex][columnIndex] = sum;
        }
    }
}

void printMatrix(int rows, int column, int (*resultMatrix)[column])
{
    printf("Mutliplication of 2 matrices:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            printf("%d ", resultMatrix[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

int main()
{

    int firstMatrixRows = 0, firstMatrixColumn = 0;
    printf("Enter rows and columns of first matrix: ");
    takeInputOfDimension(&firstMatrixRows, &firstMatrixColumn);

    int secondMatrixRows = 0, secondMatrixColumn = 0;
    printf("Enter rows and columns of second matrix: ");
    takeInputOfDimension(&secondMatrixRows, &secondMatrixColumn);

    if (firstMatrixColumn != secondMatrixRows)
    {
        printf("Multiplication of 2 matrices requires: \"no of column of first matrix = no of row of second matrix\"");
        return 0;
    }

    int firstMatrix[firstMatrixRows][firstMatrixColumn], secondMatrix[secondMatrixRows][secondMatrixColumn], resultMatrix[firstMatrixRows][secondMatrixColumn];

    takeInputOfMatrix("first", firstMatrixRows, firstMatrixColumn, firstMatrix);
    takeInputOfMatrix("second", secondMatrixRows, secondMatrixColumn, secondMatrix);

    performOperation(firstMatrixColumn, secondMatrixRows, secondMatrixColumn, firstMatrix, secondMatrix, resultMatrix);

    printMatrix(firstMatrixRows, secondMatrixColumn, resultMatrix);

    return 0;
}