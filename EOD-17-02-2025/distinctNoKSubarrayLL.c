#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

typedef struct Hashmap
{
    Node *table[TABLE_SIZE];
} Hashmap;

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(Hashmap *hashmap, int key)
{
    int index = hashFunction(key);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (hashmap->table[index] == NULL)
    {
        hashmap->table[index] = newNode;
    }
    else
    {
        newNode->next = hashmap->table[index];
        hashmap->table[index] = newNode;
    }
}

int exists(Hashmap *hashmap, int key)
{
    int index = hashFunction(key);
    Node *current = hashmap->table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void displayHashmap(Hashmap * hashmap) {
    printf("Hashmap\n");
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        if(hashmap -> table[index] != NULL) {
            Node * current = hashmap -> table[index];
            while (current != NULL)
            {
                printf("%d ", current -> key);
                current = current -> next;
            }
            printf("\n");
        }
    }    
}

void freeHashmap(Hashmap *hashmap)
{
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        Node *current = hashmap->table[index];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int countFrequency(int subArrSize, int arr[])
{
    Hashmap hashmap;
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        hashmap.table[index] = NULL;
    }

    int count = 0;
    for (int index = 0; index < subArrSize; index++)
    {
        if (!exists(&hashmap, arr[index]))
        {
            insert(&hashmap, arr[index]);
            count++;
        }
    }

    // displayHashmap(&hashmap);

    freeHashmap(&hashmap);
    return count;
}

int main()
{
    int *array;
    array = (int *)malloc(100 * sizeof(int));
    int arrayIndex = 0;

    printf("Enter array: ");
    while (1)
    {
        int number;
        scanf("%d", &number);

        array[arrayIndex++] = number;

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }

    printf("Enter size of subarray: ");
    int subArrSize;
    scanf("%d", &subArrSize);

    int resultArray[arrayIndex - subArrSize + 1];
    int resultArrayIndex = 0;

    for (int i = 0; i < arrayIndex - subArrSize + 1; i++)
    {
        resultArray[resultArrayIndex++] = countFrequency(subArrSize, &array[i]);
    }

    printf("Result: ");
    for (int i = 0; i < resultArrayIndex; i++)
    {
        printf("%d ", resultArray[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
