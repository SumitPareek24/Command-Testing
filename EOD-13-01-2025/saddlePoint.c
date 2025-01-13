#include <stdio.h>

int minimumNumber(int a, int b) {
    return a <= b ? a : b;
}

int maximumNumber(int a, int b) {
    return a >= b ? a : b;
}

int findSmallestInRow(int row, int column, int (* arr)[column]) {
    int lowestInRow = 1e9;
    for(int index = 0; index < column; index++) {
        lowestInRow = minimumNumber(lowestInRow, arr[row][index]);
    }    
    return lowestInRow;
}

int findLargestInColumn(int row, int column, int (* arr)[column]) {
    int lowestInRow = -1e9;
    for(int index = 0; index < column; index++) {
        lowestInRow = maximumNumber(lowestInRow, arr[index][row]);
    }    
    return lowestInRow;
}

int main() {

    int dimension = 0;
    printf("enter dimension: ");
    scanf("%d", &dimension);
    
    int matrix[dimension][dimension];
    printf("enter elements: \n");
    for(int row = 0; row < dimension; row++) {
        for(int column = 0; column < dimension; column++) {
            scanf("%d", &matrix[row][column]);
        }
    }

    int matrixForRow[dimension][dimension], matrixForColumn[dimension][dimension];
    int indexForRow = 0, indexForColumn = 0;

    for(int index = 0; index < dimension; index++) {
        matrixForRow[indexForRow++][index] = findSmallestInRow(index, dimension, matrix);
    }

    indexForRow = 0;

    for(int index = 0; index < dimension; index++) {
        matrixForColumn[indexForColumn++][index] = findLargestInColumn(index, dimension, matrix);
    }

    indexForColumn = 0;
    for(int index = 0; index < dimension; index++) {
        if(matrixForRow[index][1] == matrixForColumn[index][1]) {
            printf("%d\n", matrixForRow[index][1]);
            break;
        }
    }

    return 0;
}