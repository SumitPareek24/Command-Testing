#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Node
{
    char id[MAX_SIZE];
    struct Node *next;
} Node;

typedef struct
{
    char id[MAX_SIZE];
} Set;
Set set[MAX_SIZE];
int indexSet;

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

int isFound(char str[])
{
    for (int i = 0; i < indexSet; i++)
    {
        if (stringComparison(set[i].id, str) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void stringCopy(char *source, char *destination)
{
    int i = 0;
    while (*source != '\0')
    {
        destination[i] = *source;
        i++;
        source++;
    }
    destination[i] = '\0';
}

int setter(char * str)
{
    if (isFound(str) == 0)
    {
        stringCopy(str, set[indexSet].id);
        indexSet++;
        return 1;
    }
    return 0;
}

char words[MAX_SIZE][MAX_SIZE];

int countNoOfWords(char *str)
{
    int wordCount = 0;
    int wordEnd = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != ',')
        {
            words[wordCount][wordEnd++] = str[i];
        }
        else if (wordEnd > 0)
        {
            words[wordCount][wordEnd] = '\0';
            wordEnd = 0;
            wordCount++;
        }
    }

    if (wordEnd > 0)
    {
        words[wordCount][wordEnd] = '\0';
        wordCount++;
    }
    return wordCount;
}

Node *create(char *str)
{
    Node *head = NULL, *tail = NULL;
    int wordCount = countNoOfWords(str);
    int index = 0;
    while (index < wordCount)
    {
        if (setter(words[index]) == 1)
        {
            printf("");
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            stringCopy(words[index], newNode->id);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        index++;
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("\"%s\" -> ", temp->id);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    char *str = (char *)malloc(100 * sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]", str);

    head = create(str);
    display(head);
    free(str);
    return 0;
}