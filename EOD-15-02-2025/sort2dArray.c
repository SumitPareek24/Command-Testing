/*
[
[r,c,j],
[q,l,a],
[i,g,b],
]
[[r,c,j],[q,l,a],[i,g,b],]
*/

#include <stdio.h>
#include <stdlib.h>

int countRows(char *str)
{
    int count = 0;
    for (int index = 0; str[index] != '\0'; index++)
    {
        if (str[index] == ']')
        {
            count++;
        }
    }
    return count - 1;
}

int countColumns(char *str)
{
    int count = 0;
    for (int index = 2; str[index] != '\0'; index++)
    {
        if (str[index] == ']')
        {
            break;
        }
        else if (str[index] == ',')
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    return count;
}

void merge(char array[], int left, int mid, int right) {
    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;

    int leftArr[leftArrSize], rightArr[rightArrSize];

    int leftArrIndex = 0, rightArrIndex = 0, arrIndex = left;

    while (leftArrIndex < leftArrSize)
    {
        leftArr[leftArrIndex] = array[arrIndex];
        leftArrIndex++;
        arrIndex++;
    }

    while (rightArrIndex < rightArrSize)
    {
        rightArr[rightArrIndex] = array[arrIndex];
        rightArrIndex++;
        arrIndex++;
    }

    leftArrIndex = 0, rightArrIndex = 0, arrIndex = left;

    while (leftArrIndex < leftArrSize && rightArrIndex < rightArrSize) 
    {
        if(leftArr[leftArrIndex] <= rightArr[rightArrIndex]) {
            array[arrIndex++] = leftArr[leftArrIndex++];
        } else {
            array[arrIndex++] = rightArr[rightArrIndex++];
        }
    }
    
    while (leftArrIndex < leftArrSize)
    {
        array[arrIndex] = leftArr[leftArrIndex];
        leftArrIndex++;
        arrIndex++;
    }

    while (rightArrIndex < rightArrSize)
    {
        array[arrIndex] = rightArr[rightArrIndex];
        rightArrIndex++;
        arrIndex++;
    }    
}

void mergeSort(char array[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void flatten2dArray(int rows, int columns, char array[rows][columns], char flatArray[rows * columns])
{
    int flatIndex = 0;

    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < columns; colIndex++)
        {
            flatArray[flatIndex++] = array[rowIndex][colIndex];
        }
    }
}

void convertFlatIntoArray(int rows, int columns, char array[rows][columns], char flatArray[rows * columns])
{
    int flatIndex = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int colIndex = 0; colIndex < columns; colIndex++)
        {
            array[rowIndex][colIndex] = flatArray[flatIndex++];
        }
    }
}

void sort2dArray(int rows, int columns, char (*array)[columns])
{
    char flatArray[rows * columns];
    flatten2dArray(rows, columns, array, flatArray);
    mergeSort(flatArray, 0, rows * columns - 1);
    convertFlatIntoArray(rows, columns, array, flatArray);
}

void printArray(int noOfRows, int noOfColumns, char (*array)[noOfColumns]) {
    printf("array:\n");

    for (int rowIndex = 0; rowIndex < noOfRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < noOfColumns; columnIndex++)
        {
            printf("%c ", array[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

void convertStringInto2dArray(char * str, int columns, char (* array)[columns]) {
    int rowIndex = 0, columnIndex = 0;

    for (int index = 2; str[index] != '\0'; index++)
    {
        if (str[index] >= 'a' && str[index] <= 'z')
        {
            while (str[index] >= 'a' && str[index] <= 'z')
            {
                array[rowIndex][columnIndex++] = str[index];
                index++;
            }
        }
        else if (str[index] == '[')
        {
            rowIndex++;
            columnIndex = 0;
        }
    }
}

int main()
{

    char *str;

    str = (char *)malloc(1000 * sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]", str);

    int noOfRows = countRows(str);
    int noOfColumns = countColumns(str);

    char array[noOfRows][noOfColumns];

    convertStringInto2dArray(str, noOfColumns, array);

    sort2dArray(noOfRows, noOfColumns, array);

    printArray(noOfRows, noOfColumns, array);

    free(str);

    return 0;
}