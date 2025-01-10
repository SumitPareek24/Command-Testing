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

    printf("enter 2nd string: ");
    scanf("%[^\n]%*c", str2);
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

    int left = 0, right = 0, check = 0;

    while (left < n)
    {
        if (str1[left] == str2[right])
        {
            right++;
            if (right == m)
            {
                check = 1;
                break;
            }
        }
        else
        {
            left = left - right;
            right = 0;
        }
        left++;
    }

    check ? printf("%s is substring of string %s\n", str2, str1) : printf("-1\n");

    free(str1);
    free(str2);

    return 0;
}