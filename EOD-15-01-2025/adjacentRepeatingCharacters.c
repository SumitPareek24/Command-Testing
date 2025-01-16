#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

void swapCharacters(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void adjustRepeatingCharacter(char *str)
{
    while (*(str + 2) != '\0')
    {
        *str = *(str + 2);
        str++;
    }
    *str = '\0';
}

int main()
{
    char *str;
    str = (char *)malloc(1000 * sizeof(str));
    printf("Enter string: ");
    scanf("%[^\n]%*c", str);

    int length = stringLength(str);

    while (length > 1)
    {
        int flag = 0;
        for (int i = 0; i < length - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                adjustRepeatingCharacter(&str[i]);
                printf("string: %s\n", str);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
        length = stringLength(str);
        printf("length: %d\n", length);
    }
    if(length == 0) {
        printf("empty\n");
    } else {
        printf("result: %s\n", str);
    }

    return 0;
}