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

int main()
{
    char *str;
    printf("Enter string: ");
    str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));

    int arr[26] = {0};

    int lengthOfString = stringLength(str);

    for (int i = 0; i < lengthOfString; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (arr[str[i] - 'a'] == 0)
            {
                printf("%c", str[i]);
            }
            arr[str[i] - 'a']++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (arr[str[i] - 'A'] == 0)
            {
                printf("%c", str[i]);
            }
            arr[str[i] - 'A']++;
        }
    }

    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%c : %d\n", 'a' + i, arr[i]);
    // }

    free(str);

    return 0;
}