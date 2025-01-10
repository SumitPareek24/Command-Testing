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
    char * str;
    printf("Enter string: ");
    str = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    str = (char *)realloc(str, stringLength(str) * sizeof(char));

    int arr[26] = {0};

    int lengthOfString = stringLength(str);

    for(int i = 0; i < lengthOfString; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')  {
            arr[str[i] - 'a']++;
        }            
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            arr[str[i] - 'A']++;
        }
    }

    int maximumOccurence = 0;

    for(int i = 0; i < 26; i++) {
        if(maximumOccurence < arr[i]) {
            maximumOccurence = arr[i];
        }
    }

    for(int i = 0; i < 26; i++) {
        if(arr[i] == maximumOccurence) {
            printf("%c\n", 'a' + i);
        }
    }

    free(str);

    return 0;
}