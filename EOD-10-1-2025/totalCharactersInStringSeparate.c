#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

int isAlphabet(char *character)
{
    return (*character >= 'A' && *character <= 'Z') || (*character >= 'a' && *character <= 'z');
}

int isDigit(char *character)
{
    return *character >= '0' && *character <= '9';
}

void takeInput(char **str1)
{
    printf("enter string: ");
    scanf("%[^\n]%*c", *str1);
    *str1 = (char *)realloc(*str1, stringLength(*str1) * sizeof(char) + 1);
}

void printCount(char *type, int count)
{
    printf("Total number of %s: %d\n", type, count);
}

void countCharactersInString(int *totalNumberOfAlphabets,
                             int *totalNumberOfSpecialCharacters,
                             int *totalNumberOfDigits, char *str)
{
    for (int index = 0; index < stringLength(str); index++)
    {
        if (isDigit(&str[index]))
        {
            (*totalNumberOfDigits)++;
        }
        else if (isAlphabet(&str[index]))
        {
            (*totalNumberOfAlphabets)++;
        }
        else
        {
            (*totalNumberOfSpecialCharacters)++;
        }
    }
}

int main()
{

    char *str1;
    str1 = (char *)malloc(1000 * sizeof(char));
    takeInput(&str1);

    int totalNumberOfAlphabets = 0, totalNumberOfSpecialCharacters = 0, totalNumberOfDigits = 0;

    countCharactersInString(&totalNumberOfAlphabets, &totalNumberOfSpecialCharacters, &totalNumberOfDigits, str1);

    printCount("Digits", totalNumberOfDigits);
    printCount("Alphabets", totalNumberOfAlphabets);
    printCount("Special Characters", totalNumberOfSpecialCharacters);
    free(str1);
    return 0;
}