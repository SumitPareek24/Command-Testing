#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNoOfWords(char *str)
{
    int count = 1;
    while (*str != '\0')
    {
        if (*str == ',')
            count++;
        str++;
    }
    return count;
}

void swapChar(char *word1, char *word2)
{
    char temp = *word1;
    *word1 = *word2;
    *word2 = temp;
}

int stringCompare(char *string1, char *string2)
{
    while (*string1)
    {
        char *temp = string2;

        while (*temp != '\0')
        {
            if (*temp == *string1)
            {
                return 0;
            }
            temp++;
        }
        string1++;
    }
    return 1;
}

int stringLength(char *string)
{
    int length = 0;
    while (*string)
    {
        string++;
        length++;
    }
    return length;
}

void count(int size, char * stringArray[])
{
    int maximum = -1;
    for (int firstIndex = 0; firstIndex < size - 1; firstIndex++)
    {
        for (int secondIndex = firstIndex + 1; secondIndex < size; secondIndex++)
        {
            if (stringCompare(stringArray[firstIndex], stringArray[secondIndex]))
            {
                int length = stringLength(stringArray[firstIndex]) * stringLength(stringArray[secondIndex]);
                if (maximum < length)
                {
                    maximum = length;
                }
            }
        }
    }
    if (maximum == -1)
    {
        printf("0\n");
    }
    else
    {
        printf("maximum length: %d\n", maximum);
    }
}

void convertStringIntoArray(char * str, int sizeOfArray, char * stringArray[]) {
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            char tempWord[10];
            int index = 0;
            while (*str >= 'a' && *str <= 'z')
            {
                tempWord[index++] = *str;
                str++;
            }
            tempWord[index] = '\0';
            stringArray[sizeOfArray] = (char *)malloc((index + 1) * sizeof(char));
            strcpy(stringArray[sizeOfArray], tempWord);
            sizeOfArray++;
        }
        str++;
    }
}

int main()
{
    char *str;
    str = (char *)malloc(100 * sizeof(str));
    printf("Enter words: ");
    scanf("%[^\n]%*c", str);

    int noOfWords = countNoOfWords(str);

    char *stringArray[noOfWords];\
    convertStringIntoArray(str, 0, stringArray);

    count(noOfWords, stringArray);

    return 0;
}
