#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNoOfWords(char * str) {
    int count = 1;
    while (* str != '\0')
    {
        if(* str == ',')
            count++;
        str++;
    }
    return count;
}

void swapChar(char * word1, char * word2) {
    char temp = * word1;
    * word1 = * word2;
    * word2 = temp;
}

int stringCompare(char * string1, char * string2) {
    while(* string1) {
        char * temp = string2;

        while(* temp != '\0') {
            if(* temp == * string1) {
                return 0;
            }
            temp++;
        }
        string1++;
    }
    return 1;
}

int stringLength(char * string) {
    int length = 0;
    while(* string) {
        string++;
        length++;
    }
    return length;
}

void count(int size, char * stringArray) {
    int maximum = -1;
    for(int firstIndex = 0; firstIndex < size - 1; firstIndex++) {
        for (int secondIndex = firstIndex + 1; secondIndex < size; secondIndex++)
        {
            if(stringCompare(stringArray[firstIndex], stringArray[secondIndex])) {
                int length = stringLength(stringArray[firstIndex]) * stringLength(stringArray[secondIndex]);
                if(maximum < length) {
                    maximum = length;
                }
            }
        }        
    }
    if(maximum == -1) {
        printf("0\n");
    } else {
        printf("maximum length: %d\n", maximum);
    }
}

int main() {
    char * str;
    str = (char *)malloc(100 * sizeof(str));
    printf("Enter words: ");
    scanf("%[^\n]%*c", str);

    int noOfWords = countNoOfWords(str);
    printf("count: %d\n", noOfWords);

    char * stringArray[noOfWords];
    int index = 0;

    while (* str != '\0')
    {
        if(*str >= 'a' && * str <= 'z') {
            char tempWord[10];
            int i = 0;
            while(* str >= 'a' && * str <= 'z') {
                tempWord[i++] = *str;
                str++;
            }
            tempWord[i] = '\0';
            printf("temp: %s\n", tempWord);
            stringArray[index] = tempWord;
            printf("string[%d]: %s\n", index, stringArray[index]);
            index++;
        }
        str++;
    }

    for(int i = 0; i < index; i++) {
        printf("s[%d]: %s\n", i, stringArray[i]);
    }

    printf("size: %d\n", index);
    

    // printf("%s\n", str);
    return 0;
}
