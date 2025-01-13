#include <stdio.h>
#include <stdlib.h>

void findRepeatedCharacters(char * str) {
    int arr[26] = {0};

    for(int index = 0; str[index] != '\0'; index++) {
        arr[str[index] - 'a']++;
    }

    int arr2[26] = {0};

    for(int index = 0; str[index] != '\0'; index++) {
        if(arr[str[index] - 'a'] > 0 && arr2[str[index] - 'a'] == 0) {
            arr2[str[index] - 'a']++;
            printf("%c", str[index]);
        }
    }
}

int main() {

    char * str;
    str = (char*)malloc(1000 * sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]%*c", str);

    char * newStr;

    newStr = (char*)malloc(1000 * sizeof(char));

    findRepeatedCharacters(str);

    return 0;
}