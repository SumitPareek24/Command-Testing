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

int isAlphabet(char *c)
{
    return (*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z');
}

int isDigit(char *c)
{
    return *c >= '0' && *c <= '9';
}

void takeInput(char *str1)
{
    printf("enter string: ");
    scanf("%[^\n]%*c", str1);
    str1 = (char *)realloc(str1, stringLength(str1) * sizeof(char) + 1);
}

void printCount(char *type, int count)
{
    printf("Total number of %s: %d\n", type, count);
}

// void countCharactersInString(int *totalNumberOfAlphabets,
//                              int *totalNumberOfSpecialCharacters,
//                              int *totalNumberOfDigits, char *str)
// {
//     for (int i = 0; i < stringLength(str); i++)
//     {
//         if (isDigit(&str[i]))
//         {
//             (*totalNumberOfDigits)++;
//         }
//         else if (isAlphabet(&str[i]))
//         {
//             (*totalNumberOfAlphabets)++;
//         }
//         else
//         {
//             (*totalNumberOfSpecialCharacters)++;
//         }
//     }
// }

int main()
{

    char *str1;
    str1 = (char *)malloc(1000 * sizeof(char));
    takeInput(str1);    

    int totalNumberOfAlphabets = 0, totalNumberOfSpecialCharacters = 0, totalNumberOfDigits = 0;

    for (int i = 0; i < stringLength(str1); i++)
    {
        if (isDigit(&str1[i]))
        {
            totalNumberOfDigits++;
        }
        else if (isAlphabet(&str1[i]))
        {
            totalNumberOfAlphabets++;
        }
        else
        {
            totalNumberOfSpecialCharacters++;
        }
    }

    // countCharactersInString(&totalNumberOfAlphabets, &totalNumberOfSpecialCharacters, &totalNumberOfDigits, str1);

    printCount("Digits", totalNumberOfDigits);
    printCount("Alphabets", totalNumberOfAlphabets);
    printCount("Special Characters", totalNumberOfSpecialCharacters);
    free(str1);
    return 0;
}