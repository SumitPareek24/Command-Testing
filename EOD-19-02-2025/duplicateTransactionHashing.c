/*

7
101 1001 25000.0 10
102 1020 35319 80
103 5429 43143 539
110 1001 25000.0 532
106 1041 25003 131
431 5429 43143 213
112 1001 25000.0 232

*/

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct Node
{
    int transactionId;
    int userId;
    float amount;
    int timestamp;
    struct Node *next;
} Node;

int currentTableIndex;

int absoluteValue(int num) {
    return num < 0 ? -num : num;
}

Node *createNode(int transactionId, int userId, float amount, int timestamp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->transactionId = transactionId;
    newNode->userId = userId;
    newNode->amount = amount;
    newNode->timestamp = timestamp;
    return newNode;
}

int checkDuplicates(Node **hashTable, float amount, int userId, int timeStamp)
{
    for (int index = 0; index < MAXSIZE; index++)
    {
        if (hashTable[index] != NULL)
        {
            Node *temp = hashTable[index];
            if (temp -> userId == userId && temp -> amount == amount && temp -> amount <= (timeStamp - 60))
            {
                printf("Duplicate transaction detected\n");
                return index;
            }
        }
    }
    return -1;
}

void insertInTable(int transactionId, int userId, float amount, int timestamp, Node **hashTable)
{
    int position = checkDuplicates(hashTable, amount, userId, timestamp);
    if (position >= 0)
    {
        Node * temp = hashTable[position];
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = createNode(transactionId, userId, amount, timestamp);
    } else {
        hashTable[currentTableIndex++] = createNode(transactionId, userId, amount, timestamp);
    }
}

void displayHashTable(Node **hashTable)
{
    printf("Transaction details:\n");
    for (int index = 0; index < MAXSIZE; index++)
    {
        if (hashTable[index] != NULL)
        {
            Node * temp = hashTable[index];
            printf("%d:=> ", index);
            while (temp != NULL)
            {
                printf("Transaction id: %d, userId: %d, amount: %f, time: %d -> ", temp->transactionId,
                    temp->userId, temp->amount, temp->timestamp);
                temp = temp -> next;
            }
            printf("NULL");
            printf("\n");
        }
    }
}

int main()
{

    Node **hashTable = (Node **)calloc(MAXSIZE, sizeof(Node *));
    int transactionId, userId, timestamp;
    float amount;

    int tableIndex = 0;

    int noOfTransaction;
    printf("enter no of transaction: ");
    scanf("%d", &noOfTransaction);

    while (noOfTransaction--)
    {
        scanf("%d %d %f %d", &transactionId, &userId, &amount, &timestamp);
        insertInTable(transactionId, userId, amount, timestamp, hashTable);
    }

    displayHashTable(hashTable);

    free(hashTable);

    return 0;
}