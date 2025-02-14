#include <stdio.h>
#include <stdlib.h>

int countNoOfRows(char * str) {
    int count = 0;
    while(* str != '\0') {
        if(* str == ']') {
            count++;
        }
        str++;
    }
    return count - 1;
}

int countNoOfCols(char * str) {
    int count = 0;
    for(int index = 2; str[index] != '\0'; index++) {
        if(str[index] == ']') break;
        else if(str[index] == ',') continue;
        count++;
    }
    return count;
}

void swapNumbers(int * firstNo, int * secondNo) {
    int temp = * firstNo;
    * firstNo = * secondNo;
    * secondNo = temp;
}

void transposeMatrix(int noOfRows, int noOfColumns, int (* matrix)[noOfColumns]) {
    for (int rowIndex = 0; rowIndex < noOfRows; rowIndex++)
    {
        for (int colIndex = rowIndex + 1; colIndex < noOfColumns; colIndex++)
        {
            swapNumbers(&matrix[rowIndex][colIndex], &matrix[colIndex][rowIndex]);
        }
    }
}

void convertStringIntoMatrix(char * str, int columns, int (* matrix)[columns]) {
    int rowIndex = 0, colIndex = 0;

    for(int index = 0; str[index] != '\0'; index++) {
        if(str[index] >= '0' && str[index] <= '9') {
            matrix[rowIndex][colIndex++] = (str[index] - '0');
        }
        else if(str[index] == ']') {
            rowIndex++;
            colIndex = 0;
        }
    }
}

void printMatrix(int noOfRows, int noOfColumns, int (* matrix)[noOfColumns]) {
    printf("anti clock wise:\n");
    for (int rowIndex = 0; rowIndex < noOfRows; rowIndex++)
    {   
        for (int colIndex = 0; colIndex < noOfColumns; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }   

}

void reverseMatrix(int noOfRows, int noOfColumns, int (* matrix)[noOfColumns]) {
    for(int i = 0; i < noOfRows; i++) {
        int start = 0, end = noOfColumns - 1;
        while(start < end) {
            swapNumbers(&matrix[start][i], &matrix[end][i]);
            start++;
            end--;
        }
    }
}

int main() {

    char * str;
    str = (char *)malloc(100 * sizeof(str));
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

    transposeMatrix(noOfRows, noOfColumns, matrix);
    reverseMatrix(noOfRows, noOfColumns, matrix);

    printMatrix(noOfRows, noOfColumns, matrix);

    free(str);

    return 0;
}
