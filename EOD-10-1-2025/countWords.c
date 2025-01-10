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
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != ',')
        {
            arr[wordCount][wordEnd] = str[i];
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

void takeInput(char * str) {
   
    printf("enter string: ");
    scanf("%[^\n]%*c", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));
}

int main()
{

    char * str;
    str = (char *)malloc(1000 * sizeof(char));
    takeInput(str);
    char arr[100][100];

    int countOfWords = splitWords(str, arr);
    printf("Number of Words: %d\n", countOfWords);
    free(str);

    return 0;
}