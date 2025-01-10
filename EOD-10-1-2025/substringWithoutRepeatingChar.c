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

void checkSubstring(char * arr, char * str) {
    int maxi = 0;
    int current = 0;
    int left = 0;
    for (int right = 0; right < stringLength(str); right++)
    {
        while(arr[str[right] - 'a'] > 0) { 
            arr[str[left] - 'a']--;
            left++;
        }

        arr[str[right] - 'a']++;

        if (maxi < right - left + 1)
        {
            maxi = right - left + 1;
        }
    }

    printf("%d\n", maxi);
}

int main()
{
    char arr[26] = {0};

    char *str;
    str = (char *)malloc(1000 * sizeof(char));
    printf("Enter string: ");
    scanf("%s", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));

    checkSubstring(arr, str);

    return 0;
}