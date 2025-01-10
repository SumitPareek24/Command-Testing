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

void takeInput(char *str1, char *str2)
{
    printf("enter 1st string: ");
    scanf("%[^\n]%*c", str1);
    // str1 = (char *)realloc(str1, stringLength(str1) * sizeof(char) + 1);

    printf("enter 2nd string: ");
    scanf("%[^\n]%*c", str2);
    // str2 = (char *)realloc(str2, stringLength(str2) * sizeof(char) + 1);
}

void checkString(char *str1, char *str2)
{
}

int main()
{

    char *str1;
    str1 = (char *)malloc(1000 * sizeof(char));

    char *str2;
    str2 = (char *)malloc(1000 * sizeof(char));

    takeInput(str1, str2);

    int n = stringLength(str1);
    int m = stringLength(str2);

    int i = 0, j = 0, check = 0;

    while (i < n)
    {
        if (str1[i] == str2[j])
        {
            j++;
            if (j == m)
            {
                check = 1;
                break;
            }
        }
        else
        {
            i = i - j;
            j = 0;
        }
        i++;
    }

    check ? printf("%s is substring of string %s\n", str2, str1) : printf("-1\n");

    free(str1);
    free(str2);

    return 0;
}