#include <stdio.h>

void takeInputOfDimension(int * dimension) {
    printf("Enter dimension of square matrix: ");
    scanf("%d", dimension);
}

void takeInputOfArray(int dimension, int (* matrix)[dimension]) {
    printf("Enter elements of square matrix:\n");
    for(int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        for(int columnIndex = 0; columnIndex < dimension; columnIndex++) {
            scanf("%d", &matrix[rowIndex][columnIndex]);
        }
    }
}

void transposeOfMatrix(int dimension, int (* matrix)[dimension]) {
    for(int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        for(int columnIndex = rowIndex + 1; columnIndex < dimension; columnIndex++) {
            int temp = matrix[rowIndex][columnIndex];
            matrix[rowIndex][columnIndex] = matrix[columnIndex][rowIndex];
            matrix[columnIndex][rowIndex] = temp;
        }
    }
}

void reverseMatrixRowWise(int dimension, int (* matrix)[dimension]) {
    for(int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        int start = 0, end = dimension - 1;
        while (start < end)
        {
            int temp = matrix[rowIndex][start];
            matrix[rowIndex][start] = matrix[rowIndex][end];
            matrix[rowIndex][end] = temp;
            start++;
            end--;
        }        
    }
}

void printMatrix(int dimension, int (* matrix)[dimension]) {
    for(int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        for(int columnIndex = 0; columnIndex < dimension; columnIndex++) {
            printf("%d ", matrix[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

int main()
{
    int dimension;
    takeInputOfDimension(&dimension);
    int matrix[dimension][dimension];

    takeInputOfArray(dimension, matrix);

    transposeOfMatrix(dimension, matrix);

    reverseMatrixRowWise(dimension, matrix);

    printMatrix(dimension, matrix);

    return 0;
}