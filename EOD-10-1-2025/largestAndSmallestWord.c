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

int splitWords(char *str, char (*arr)[100])
{
    int wordCount = 0, wordEnd = 0;
    for (int index = 0; str[index] != '\0'; index++)
    {
        if (str[index] != ' ' && str[index] != ',')
        {
            arr[wordCount][wordEnd] = str[index];
            wordEnd++;
        }
        else if (wordEnd > 0)
        {
            arr[wordCount][wordEnd] = '\0';
            wordEnd = 0;
            wordCount++;
        }
    }
    if (wordEnd > 0)
    {
        arr[wordCount][wordEnd] = '\0';
        wordCount++;
    }
    return wordCount;
}

void takeInput(char **str)
{
    printf("enter string: ");
    scanf("%[^\n]%*c", *str);
    *str = (char *)realloc(*str, stringLength(*str) * sizeof(char) + 1);
}

void findLargestAndSmallestWord(char **smallestString, char **largestString, int countOfWords, char (*arr)[100])
{
    int minimum = 1e9, maximum = -1;
    for (int index = 0; index < countOfWords; index++)
    {
        int len = stringLength(arr[index]);
        if (len > maximum)
        {
            maximum = len;
            * largestString = arr[index];
        }
        if (len < minimum)
        {
            minimum = len;
            * smallestString = arr[index];
        }
    }
}

int main()
{
    char *str;
    str = (char *)malloc(1000 * sizeof(char));
    takeInput(&str);
    char arr[100][100];

    int countOfWords = splitWords(str, arr);

    char *smallestString, *largestString;
    findLargestAndSmallestWord(&smallestString, &largestString, countOfWords, arr);

    printf("largest word: %s\n", largestString);
    printf("smallest word: %s\n", smallestString);

    free(str);

    return 0;
}