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

int main()
{
    char arr[26] = {0};

    char *str;
    str = (char *)malloc(1000 * sizeof(char));
    printf("Enter string: ");
    scanf("%s", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));

    int maxi = 0;
    int current = 0;
    int j = 0;
    for (int i = 0; i < stringLength(str); i++)
    {
        while(arr[str[i] - 'a'] > 0) { 
            arr[str[j] - 'a']--;
            j++;
        }

        arr[str[i] - 'a']++;

        if (maxi < i - j + 1)
        {
            maxi = i - j + 1;
        }
    }

    printf("%d\n", maxi);

    return 0;
}