#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLength(char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void swapNumber(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void recursion(char * str, int size, int index, char (*arr)[size])
{
    if (index == size)
    {
        printf("%s\n", str);
        return;
    }

    for (int i = index; i < size; i++)
    {
        swapNumber(&str[index], &str[i]);
        recursion(str, size, index + 1, arr);
        swapNumber(&str[index], &str[i]);
    }
}

int main()
{
    char *str;
    printf("Enter string: ");
    str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));

    int lengthOfString = stringLength(str);

    char arr[lengthOfString * (lengthOfString - 1)][lengthOfString];

    recursion(str, lengthOfString, 0, arr);
    free(str);

    return 0;
}