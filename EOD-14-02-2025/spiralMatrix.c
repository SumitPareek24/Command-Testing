#include <stdio.h>
#include <stdlib.h>

int countNoOfRows(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        if (*str == ']')
        {
            count++;
        }
        str++;
    }
    return count - 1;
}

int countNoOfCols(char *str)
{
    int count = 0;
    for (int index = 2; str[index] != '\0'; index++)
    {
        if (str[index] == ']')
            break;
        else if (str[index] == ',')
            continue;
        count++;
    }
    return count;
}

void swapNumbers(int *firstNo, int *secondNo)
{
    int temp = *firstNo;
    *firstNo = *secondNo;
    *secondNo = temp;
}

void convertStringIntoMatrix(char * str, int columns, int (* matrix)[columns]) {
    int rowIndex = 0, colIndex = 0;

    for (int index = 0; str[index] != '\0'; index++)
    {
        if (str[index] >= '0' && str[index] <= '9')
        {
            int number = 0;
            while (str[index] >= '0' && str[index] <= '9')
            {
                number = number * 10 + (str[index] - '0');
                index++;
            }           
            matrix[rowIndex][colIndex++] = number;
        }
        else if (str[index] == ']')
        {
            rowIndex++;
            colIndex = 0;
        }
    }
}

void printMatrix(int noOfRows, int noOfColumns, int (* matrix)[noOfColumns]) {
    int top = 0, bottom = noOfRows - 1;
    int left = 0, right = noOfColumns - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
        }
        right--;

        if(top < bottom) {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        if(left < right) {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main()
{

    char *str;
    str = (char *)malloc(100 * sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]", str);

    int noOfRows = countNoOfRows(str);
    int noOfColumns = countNoOfCols(str);

    printf("Rows: %d\n", noOfRows);
    printf("Columns: %d\n", noOfColumns);

    int matrix[noOfRows][noOfColumns];

    convertStringIntoMatrix(str, noOfColumns, matrix);

    printf("matrix:\n");

    for (int rowIndex = 0; rowIndex < noOfRows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < noOfColumns; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }

    printf("\n");

    printMatrix(noOfRows, noOfColumns, matrix);

    free(str);

    return 0;
}