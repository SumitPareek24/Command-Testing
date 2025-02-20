#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAXBOOKMARKS 100

int myStack[MAXBOOKMARKS];
int top = -1;

void addBookmarks(int page)
{
    if (top < MAXBOOKMARKS - 1)
    {
        myStack[++top] = page;
    }
}

void deleteBookmark()
{
    if (top >= 0)
    {
        top--;
    }
}

void swapNumbers(int * number1, int * number2) {
    int temp = * number1; 
    * number1 = * number2;
    * number2 = temp;
}

void listBookmarks()
{
    if(top == -1) {
        printf("NO bookmarks\n");
        return;
    }

    int sorted[MAXBOOKMARKS];
    for (int i = 0; i < MAXBOOKMARKS; i++)
    {
        sorted[i] = myStack[i];
    }

    for (int firstIndex = 0; firstIndex < MAXBOOKMARKS; firstIndex++)
    {
        for (int secondIndex = firstIndex + 1; secondIndex < MAXBOOKMARKS; secondIndex++)
        {
            if(sorted[firstIndex] >= sorted[secondIndex])
                swapNumbers(&sorted[firstIndex], &sorted[secondIndex]);
        }
    }
    printf("Bookmarks:\n");
    for (int i = 0; i < MAXBOOKMARKS; i++)
    {
        printf("%d ", sorted[i]);
    }
}

void stringCopy(char *source, char destination[])
{
    int index = 0;
    while (*source)
    {
        destination[index++] = *source;
        source++;
    }
    destination[index] = '\0';
}

int stringComparison(char *string1, char *string2)
{
    while (*string1 && *string2)
    {
        if (*string1 != *string2)
        {
            return -1;
        }
        string1++;
        string2++;
    }
    return *string1 - *string2;
}

int main()
{

    int noOfOperations;
    printf("enter no of operations: ");
    scanf("%d", &noOfOperations);

    getchar();
    char *string = (char *)malloc(20 * sizeof(char));

    while (noOfOperations--)
    {
        printf("Enter string: ");
        scanf("%[^\n]", string);
        getchar();
        int pageNo;

        if (sscanf(string, "\"%*s %d\"", &pageNo) == 1)
        {
            addBookmarks(pageNo);
        }
        else if (stringComparison(string, "\"DELETE\"") == 0)
        {
            deleteBookmark();
        }
        else if (stringComparison(string, "\"LIST\"") == 0)
        {
            listBookmarks();
        }
    }

    free(string);

    return 0;
}