#include <stdio.h>
#include <stdlib.h>

int stringLength(char * str) {
    int length = 0;
    while (* str != '\0')
    {
        str++;
        length++;
    }
    return length;
}

int precedence(char word) {
    if(word == '+' || word == '-')  {
        return 1;
    } else if(word == '*' || word == '/')  {
        return 2;
    } else if(word == '^') {
        return 3;
    } else {
        return 0;
    }
}

void infixToPostfix(int lengthOfString, char *str) {
    char stack[lengthOfString];
    int top = -1;
    printf("Postfix expression");
    for(int index = 0; index < lengthOfString; index++) {
        if((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= '0' && str[index] <= '9')) {
            printf("%c", str[index]);
        }
        else if(str[index] == '(') {
            top++;
            stack[top] = str[index];
        } else if(str[index] == ')') {
            while(top != -1 && stack[top] != '(') {
                printf("%c", stack[top]);
                top--;
            }
            top--;
        } else if(str[index] == '*' || str[index] == '/' || str[index] == '+' || str[index] == '-') {
            while(top != -1 && precedence(stack[top]) >= precedence(str[index])) {
                printf("%c", stack[top]);
                top--;
            }
            top++;
            stack[top] = str[index];
        }
    }

    while (top != -1) {
        printf("%c", stack[top--]);
    }
}

int main() {

    char * str = (char *)malloc(100 * sizeof(str));
    printf("enter string: ");
    scanf("%[^\n]%*c", str);
    
    int lengthOfString = stringLength(str);
    infixToPostfix(lengthOfString, str);

    return 0;
}