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

void checkString(char *str1, char *str2)
{
    int check = 1;
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            check = 0;
            break;
        }
        str1++;
        str2++;
    }
    check ? printf("Both strings are equal\n") : printf("Both strings are not equal\n");
}

void takeInput(char * str1, char * str2) {
    printf("enter 1st string: ");
    scanf("%[^\n]%*c", str1);
    str1 = (char *)realloc(str1, stringLength(str1) * sizeof(char));

    printf("enter 2nd string: ");
    scanf("%[^\n]%*c", str2);
    str2 = (char *)realloc(str2, stringLength(str2) * sizeof(char));
}

int main()
{

    char * str1;
    str1 = (char *)malloc(1000 * sizeof(char));

    char * str2;
    str2 = (char *)malloc(1000 * sizeof(char));
    
    takeInput(str1, str2);

    if (stringLength(str1) != stringLength(str2))
    {
        printf("Both strings are not equal\n");
    }
    else
    {
        checkString(str1, str2);
    }

    free(str1);
    free(str2);

    return 0;
}