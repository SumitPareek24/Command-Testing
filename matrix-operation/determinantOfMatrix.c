#include <stdio.h>
#include <stdlib.h>

int determinantOfMatrix(int dimension, int (* matrix)[dimension])
{

    if (dimension == 1)
    {
        return matrix[0][0];
    }

    if (dimension == 2)
    {
        return matrix[0][0] * matrix[1][1] -
               matrix[0][1] * matrix[1][0];
    }

    int result = 0;

    for (int column = 0; column < dimension; ++column)
    {
        int subMatrix[dimension - 1][dimension - 1];
        for (int matrixRow = 1; matrixRow < dimension; ++matrixRow)
        {
            int subCol = 0;
            for (int matrixColumn = 0; matrixColumn < dimension; ++matrixColumn)
            {
                if (matrixColumn == column)
                    continue;
                subMatrix[matrixRow - 1][subCol++] = matrix[matrixRow][matrixColumn];
            }
        }

        int sign = (column % 2 == 0) ? 1 : -1;
        result += sign * matrix[0][column] * determinantOfMatrix(dimension - 1, subMatrix);
    }
    return result;
}

int main()
{

    int dimension;
    printf("Enter dimension of square matrix\n");
    scanf("%d", &dimension);

    int matrix[dimension][dimension];
    printf("Enter elements of matrix:\n");

    for (int row = 0; row < dimension; row++)
    {
        for (int column = 0; column < dimension; column++)
        {
            scanf("%d", &matrix[row][column]);
        }
    }

    printf("%d\n", determinantOfMatrix(dimension, matrix));

    return 0;
}