#include <stdio.h>
#include <stdlib.h>

int stringLength(char * str)
{
    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

void swapCharacters(char * a, char * b) { 
    char temp = * a;
    * a = * b;
    * b = temp;
}

void removeCharacter(char * str, char check) {
    int j = 0;
    for (int i = 0; i < stringLength(str); i++)
    {   
        if(str[i] != check) {
            swapCharacters(&str[i], &str[j]);
            j++;
        } else {
            continue;
        }
    }

    str[j] = '\0';
}

int main()
{
    char * str;
    str = (char *)malloc(1000 * sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]%*c", str);

    char check;
    printf("Enter character to remove from string: ");
    scanf("%c", &check);

    removeCharacter(str, check);

    printf("result: %s\n", str);

    free(str);

    return 0;
}