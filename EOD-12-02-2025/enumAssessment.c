#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    ONE,
    LOG_N,
    SQRT_N,
    N,
    N_LOG_N,
    N_POW_K,
    TWO_POW_N,
    N_FACT
} Complexity;

typedef struct Node
{
    Complexity timeComplexity, spaceComplexity;
    struct Node *next;
} Node;

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

Node *takeInput(Node *head, int noOfOperations, Node *current)
{
    while (noOfOperations--)
    {
        char *timeC, *spaceC;
        timeC = (char *)malloc(sizeof(char) * 10);
        spaceC = (char *)malloc(sizeof(char) * 10);
        scanf("%s%s", timeC, spaceC);

        Node *newNode = (Node *)malloc(sizeof(Node));

        newNode->next = NULL;

        if (stringComparison(timeC, "1") == 0)
        {
            newNode->timeComplexity = ONE;
        }
        else if (stringComparison(timeC, "logn") == 0)
        {
            newNode->timeComplexity = LOG_N;
        }
        else if (stringComparison(timeC, "sqrt(n)") == 0)
        {
            newNode->timeComplexity = SQRT_N;
        }
        else if (stringComparison(timeC, "n") == 0)
        {
            newNode->timeComplexity = N;
        }
        else if (stringComparison(timeC, "nlogn") == 0)
        {
            newNode->timeComplexity = N_LOG_N;
        }
        else if (stringComparison(timeC, "n^k") == 0)
        {
            newNode->timeComplexity = N_POW_K;
        }
        else if (stringComparison(timeC, "2^n") == 0)
        {
            newNode->timeComplexity = TWO_POW_N;
        }
        else if (stringComparison(timeC, "n!") == 0)
        {
            newNode->timeComplexity = N_FACT;
        }

        if (stringComparison(spaceC, "1") == 0)
        {
            newNode->spaceComplexity = ONE;
        }
        else if (stringComparison(spaceC, "logn") == 0)
        {
            newNode->spaceComplexity = LOG_N;
        }
        else if (stringComparison(spaceC, "sqrt(n)") == 0)
        {
            newNode->spaceComplexity = SQRT_N;
        }
        else if (stringComparison(spaceC, "n") == 0)
        {
            newNode->spaceComplexity = N;
        }
        else if (stringComparison(spaceC, "nlogn") == 0)
        {
            newNode->spaceComplexity = N_LOG_N;
        }
        else if (stringComparison(spaceC, "n^k") == 0)
        {
            newNode->spaceComplexity = N_POW_K;
        }
        else if (stringComparison(spaceC, "2^n") == 0)
        {
            newNode->spaceComplexity = TWO_POW_N;
        }
        else if (stringComparison(spaceC, "n!") == 0)
        {
            newNode->spaceComplexity = N_FACT;
        }

        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *leftHead, Node *rightHead)
{
    Node *tempHead = NULL, *tempEnd = NULL;

    if (leftHead->timeComplexity < rightHead->timeComplexity)
    {
        tempHead = leftHead;
        tempEnd = leftHead;
        leftHead = leftHead->next;
    }
    else if (leftHead->timeComplexity > rightHead->timeComplexity)
    {
        tempHead = rightHead;
        tempEnd = rightHead;
        rightHead = rightHead->next;
    }
    else
    {
        if (leftHead->spaceComplexity <= rightHead->spaceComplexity)
        {
            tempHead = leftHead;
            tempEnd = leftHead;
            leftHead = leftHead->next;
        }
        else
        {
            tempHead = rightHead;
            tempEnd = rightHead;
            rightHead = rightHead->next;
        }
    }

    while (leftHead && rightHead)
    {
        if (leftHead->timeComplexity <= rightHead->timeComplexity)
        {
            tempEnd->next = leftHead;
            leftHead = leftHead->next;
        }
        else if (leftHead->timeComplexity > rightHead->timeComplexity)
        {
            tempEnd->next = rightHead;
            rightHead = rightHead->next;
        }
        tempEnd = tempEnd->next;
    }

    if (leftHead != NULL)
    {
        tempEnd->next = leftHead;
    }

    if (rightHead != NULL)
    {
        tempEnd->next = rightHead;
    }

    return tempHead;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middle = findMiddle(head);

    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

char *mapComplexity(int complexity)
{
    if (complexity == 0)
    {
        return "1";
    }
    else if (complexity == 1)
    {
        return "logn";
    }
    else if (complexity == 2)
    {
        return "sqrt(n)";
    }
    else if (complexity == 3)
    {
        return "n";
    }
    else if (complexity == 4)
    {
        return "nlogn";
    }
    else if (complexity == 5)
    {
        return "n^k";
    }
    else if (complexity == 6)
    {
        return "2^n";
    }
    else if (complexity == 7)
    {
        return "n!";
    }
}

int main()
{
    Node *head = NULL, *current = NULL;
    int noOfOperations;
    printf("No of operations: ");
    scanf("%d", &noOfOperations);
    head = takeInput(head, noOfOperations, current);

    Node *headSorted = mergeSort(head);
    printf("\n");
    while (headSorted != NULL)
    {
        printf("%s, %s\n", mapComplexity(headSorted -> timeComplexity), mapComplexity(headSorted -> spaceComplexity));
        headSorted = headSorted->next;
    }

    return 0;
}