#include <stdio.h>

void swapNumber(int * a, int * b)
{
    int temp = * a;
    * a = * b;
    * b = temp;
}

void rotateClockWise(int row, int column, int (* matrix)[column]) {
    int j = 0;
    int top = 0, left = 0, bottom = row - 1, right = column - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = top; i < bottom; i++)
        {
            swapNumber(&matrix[i][j], &matrix[i + 1][j]);
        }

        j = bottom;
        for (int i = left; i < right; i++)
        {
            swapNumber(&matrix[j][i], &matrix[j][i + 1]);
        }

        for (int i = bottom; i > top; i--)
        {
            swapNumber(&matrix[i][j], &matrix[i - 1][j]);
        }

        j = left;
        for (int i = right; i > left + 1; i--)
        {
            swapNumber(&matrix[j][i], &matrix[j][i - 1]);
        }
        top++;
        left++;
        right--;
        bottom--;
    }
}

void takeInput(int row, int column, int (* matrix)[column]) {
    printf("enter matrix: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int row, int column, int (* matrix)[column]) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int row, column;
    printf("enter row & column: ");
    scanf("%d %d", &row, &column);

    int matrix[row][column];

    takeInput(row, column, matrix);

    rotateClockWise(row, column, matrix);

    printMatrix(row, column, matrix);

    return 0;
}