#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        str++;
        length++;
    }
    return length;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPrefix(int lengthOfString, char *str, char *prefixString) {
    char stack[lengthOfString];
    int prefixIndex = 0;
    int top = -1;
    
    for (int index = 0; index < lengthOfString; index++) {
        char currentChar = str[index];
        
        if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= '0' && currentChar <= '9')) {
            prefixString[prefixIndex++] = currentChar;
        }
        else if (currentChar == '(') {
            stack[++top] = currentChar;
        } 
        else if (currentChar == ')') {
            while (top != -1 && stack[top] != '(') {
                prefixString[prefixIndex++] = stack[top--];
            }
            top--;  // Pop '('
        } 
        else if (currentChar == '*' || currentChar == '/' || currentChar == '+' || currentChar == '-') {
            while (top != -1 && precedence(stack[top]) >= precedence(currentChar)) {
                prefixString[prefixIndex++] = stack[top--];
            }
            stack[++top] = currentChar;
        }
    }

    // Pop the remaining operators from the stack
    while (top != -1) {
        prefixString[prefixIndex++] = stack[top--];
    }
    prefixString[prefixIndex] = '\0';  // Null-terminate the string
}

void swapCharacters(char *word1, char *word2) {
    char temp = *word1;
    *word1 = *word2;
    *word2 = temp;
}

void reverseString(char *str, int lengthOfString) {
    int start = 0, end = lengthOfString - 1;
    while (start < end) {
        swapCharacters(&str[start], &str[end]);
        start++;
        end--;
    }
}

int main() {
    char *str = (char *)malloc(100 * sizeof(char));  // Correct memory allocation
    if (!str) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter infix expression: ");
    if (scanf("%[^\n]%*c", str) != 1) {  // Added input validation
        printf("Invalid input!\n");
        free(str);
        return 1;
    }

    int lengthOfString = stringLength(str);

    // Reverse the string to convert infix to prefix
    reverseString(str, lengthOfString);

    char *prefixString = (char *)malloc((lengthOfString + 1) * sizeof(char));  // Ensure space for null-terminator
    if (!prefixString) {
        printf("Memory allocation failed!\n");
        free(str);
        return 1;
    }

    infixToPrefix(lengthOfString, str, prefixString);

    // Reverse the result to get the correct prefix notation
    reverseString(prefixString, stringLength(prefixString));

    printf("Prefix expression: %s\n", prefixString);

    free(str);
    free(prefixString);

    return 0;
}
