#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct Node
{
    char word[SIZE];
    struct Node *next;
} Node;

int tableIndex;

int countNoOfString(char *string)
{
    int count = 1;
    while (*string)
    {
        if (*string == ',')
            count++;
        string++;
    }
    return count;
}

void stringCopy(char *source, char *destination)
{
    int index = 0;
    while (*source)
    {
        destination[index++] = *source;
        source++;
    }
    destination[index] = '\0';
}

int lengthOfString(char *string)
{
    int length = 0;
    while (*string)
    {
        length++;
        string++;
    }
    return length;
}

int checkAnagram(char *string1, char *string2)
{
    int string1Length = lengthOfString(string1);
    int string2Length = lengthOfString(string2);

    if (string1Length != string2Length)
    {
        return 0;
    }

    int freqArray[26] = {0};

    while (*string1)
    {
        freqArray[*string1 - 'a']++;
        string1++;
    }

    while (*string2)
    {
        freqArray[*string2 - 'a']--;
        string2++;
    }

    for (int index = 0; index < 26; index++)
    {
        if (freqArray[index] != 0)
        {
            return 0;
        }
    }
    return 1;
}

Node *createNode(char string[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    stringCopy(string, newNode->word);
    return newNode;
}

void checkAnagramExists(Node **HashMap, char *string, int noOfString)
{
    for (int index = 0; index < noOfString; index++)
    {
        if (HashMap[index] != NULL)
        {
            Node *temp = HashMap[index];
            while (temp != NULL)
            {
                if (checkAnagram(temp->word, string))
                {
                    Node *newNode = createNode(string);
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            }
        }
        else
        {
            HashMap[index] = createNode(string);
            printf("new string: %s, index: %d\n", string, index);
            return;
        }
    }
}

void insertInMap(char *stringArray[], int noOfString, Node **HashMap)
{
    for (int index = 0; index < noOfString; index++)
    {
        checkAnagramExists(HashMap, stringArray[index], noOfString);
    }
}

void displayHashmap(Node **Hashmap, int noOfString)
{
    for (int index = 0; index < noOfString; index++)
    {
        if (Hashmap[index] != NULL)
        {
            Node *temp = Hashmap[index];
            printf("%d: ", index);
            while (temp != NULL)
            {
                printf("(%s) -> ", temp->word);
                temp = temp->next;
            }
            printf("NULL");
            printf("\n");
        }
    }
}

int main()
{
    char *string = (char *)malloc(100 * sizeof(string));
    printf("Enter string: ");
    scanf("%[^\n]", string);

    int noOfString = countNoOfString(string);
    Node **HashTable;
    HashTable = (Node **)calloc(noOfString, sizeof(Node *));

    char *stringArray[noOfString];
    int arrayIndex = 0;

    for (int index = 0; string[index] != '\0'; index++)
    {
        if (string[index] >= 'a' && string[index] <= 'z')
        {
            char tempArray[20];
            int tempArrIndex = 0;
            while (string[index] >= 'a' && string[index] <= 'z')
            {
                tempArray[tempArrIndex++] = string[index++];
            }
            stringArray[arrayIndex] = (char *)malloc((tempArrIndex + 1) * sizeof(char));
            tempArray[tempArrIndex] = '\0';
            stringCopy(tempArray, stringArray[arrayIndex++]);
        }
    }

    insertInMap(stringArray, noOfString, HashTable);
    displayHashmap(HashTable, noOfString);

    free(string);

    return 0;
}