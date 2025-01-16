#include <stdio.h>
#include <stdlib.h>

int stringLength(char * str) {
    int len = 0;
    while(* str != '\0') {
        str++;
        len++;
    }
    return len;
}

int isPalindromic(char * str, int start, int end) {
    while(start <= end) {
        if(str[start] != str[end]) {
            return 0;
            break;
        }
        start++;
        end--;
    }
    return 1;
}

int maximumNumber(int number1, int number2) {
    return number1 >= number2 ? number1 : number2;
}

int main() {

    char * str;
    str = (char *)malloc(1000 * sizeof(str));
    printf("enter string: ");
    scanf("%[^\n]%*c", str);

    int maximum = 0;
    char * longestPalindromeSubstring;
    longestPalindromeSubstring = (char *)malloc(1000 * sizeof(longestPalindromeSubstring));
    int palindromeSubstringIndex = 0;

    for(int start = 0; start < stringLength(str); start++) {
        for(int end = start + 1; end < stringLength(str); end++) {
            if(isPalindromic(str, start, end)) {
                maximum = maximumNumber(maximum, end - start + 1);
                for(int substringIndex = start; substringIndex <= end; substringIndex++) {
                    longestPalindromeSubstring[palindromeSubstringIndex++] = str[substringIndex];
                }
                palindromeSubstringIndex = 0;
            }
        }
    }
    if(maximum == 0) {
        printf("%c\n", str[0]);
    } else {
        printf("length: %d\n", maximum);
        printf("substring: %s\n", longestPalindromeSubstring);
    }
    
    free(str);
    free(longestPalindromeSubstring);

    return 0;
}