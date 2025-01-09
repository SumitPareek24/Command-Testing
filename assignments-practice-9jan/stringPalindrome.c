#include <stdio.h>
#include <stdlib.h>

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

void checkPalindrome(char * str)
{
    int firstIndex = 0;
    int lastIndex = stringLength(str) - 1;
    int check = 1;

    while (firstIndex < lastIndex)
    {
        if (str[firstIndex] != str[lastIndex])
        {
            check = 0;
            break;
        }
        firstIndex++;
        lastIndex--;
    }
    check ? printf("String is palindrome") : printf("String is not palindrome");
}

int main()
{

    char * str;
    printf("Enter string: ");
    str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));
    checkPalindrome(str);
    free(str);

    return 0;
}