#include <stdio.h>
#include <stdlib.h>

int countStrings(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        if (*str == ',')
        {
            count++;
        }
        str++;
    }
    return count;
}

void stringCopy(char * source, char * destination) {
    int i = 0;
    while(* source != '\0') {
        destination[i++] = * source;
        source++;
    }
    destination[i] = '\0';
}

int stringCompare(char * string1, char * string2) {
    while (*string1 && *string2)
    {
        if(* string1 != * string2) {
            return * string1 - * string2;
        }

        string1++;
        string2++;
    }
    return * string1 - * string2;
}

void merge(char * str[], int left, int mid, int right) {
    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;
    char * leftArr[leftArrSize], * rightArr[rightArrSize];
    int leftIndex = 0, rightIndex = 0, arrIndex = left;
    while (leftIndex < leftArrSize)
    {
        
        leftArr[leftIndex] = str[arrIndex];
        leftIndex++;
        arrIndex++;
    }

    while (rightIndex < rightArrSize)
    {
        rightArr[rightIndex] = str[arrIndex];
        rightIndex++;
        arrIndex++;
    }

    leftIndex = 0, rightIndex = 0, arrIndex = left;

    while (leftIndex < leftArrSize && rightIndex < rightArrSize)
    {
        if(stringCompare(leftArr[leftIndex], rightArr[rightIndex]) < 0) {
            str[arrIndex] = leftArr[leftIndex];
            arrIndex++;
            leftIndex++;
        } else {
            str[arrIndex] = rightArr[rightIndex];
            arrIndex++;
            rightIndex++;
        }
    }
    
    while (leftIndex < leftArrSize)
    {
        str[arrIndex++] = leftArr[leftIndex++];
    }

    while (rightIndex < rightArrSize)
    {
        str[arrIndex++] = rightArr[rightIndex++];
    }
}

void sortLexo(char * str[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        sortLexo(str, left, mid);
        sortLexo(str, mid + 1, right);

        merge(str, left, mid, right);
    }
}

int main()
{

    char *str;
    str = (char *)malloc(100 * sizeof(str));
    printf("Enter string: ");
    scanf("%[^\n]", str);

    int noOfString = countStrings(str) + 1;

    char *stringArray[noOfString];

    int stringIndex = 0, stringArrIndex = 0;
    while (str[stringIndex] != '\0')
    {
        if (str[stringIndex] >= 'a' && str[stringIndex] <= 'z')
        {
            char temp[100];
            int tempIndex = 0;
            while (str[stringIndex] >= 'a' && str[stringIndex] <= 'z')
            {
                temp[tempIndex] = str[stringIndex];
                tempIndex++;
                stringIndex++;
            }
            temp[tempIndex] = '\0';
            stringArray[stringArrIndex] = (char *)malloc((tempIndex + 1) * sizeof(char));
            stringCopy(temp, stringArray[stringArrIndex]);
            stringArrIndex++;
        } else {
            stringIndex++;
        }
    }

    sortLexo(stringArray, 0, noOfString - 1);

    for (int index = 0; index < noOfString; index++)
    {
        printf("s[%d]: %s\n", index, stringArray[index]);
    }

    char string1[100], string2[100];
    char resultString[100];

    stringCopy(stringArray[0], string1);
    stringCopy(stringArray[noOfString - 1], string2);

    int string1Index = 0, string2Index = 0;
    int resultStringIndex = 0;
    while (string1[string1Index] != '\0' && string2[string2Index] != '\0') 
    {
        if(string1[string1Index] == string2[string2Index]) {
            resultString[resultStringIndex++] = string1[string1Index];
        }
        string1Index++; 
        string2Index++;
    }

    printf("Resultant string: %s\n", resultString);

    free(str);

    return 0;
}