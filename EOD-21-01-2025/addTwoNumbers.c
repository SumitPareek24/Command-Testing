#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
};

void takeInput(char *linkedListNo, struct SinglyLinkedList **head, struct SinglyLinkedList **current)
{

    printf("Enter %s Linked List: ", linkedListNo);
    while (1)
    {
        int number;
        scanf("%d", &number);
        struct SinglyLinkedList *newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
        newNode->data = number;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            (*current)->next = newNode;
        }

        *current = newNode;

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
}

int lengthOfLinkedList(struct SinglyLinkedList *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

void printLinkedList(char *linkedListNo, struct SinglyLinkedList *head)
{
    printf("%s Linked List: ", linkedListNo);

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int arr[10] = {0};

int addTwoNumbers(struct SinglyLinkedList **head1, struct SinglyLinkedList **head2)
{

    int sum = 0;

    struct SinglyLinkedList *temp1 = *head1;
    struct SinglyLinkedList *temp2 = *head2;

    int carry = 0, index = 0;

    while (temp1 != NULL || temp2 != NULL || carry > 0)
    {
        if (temp1 != NULL)
        {
            sum = sum + (temp1->data) + carry;
            temp1 = temp1->next;
        }

        if (temp2 != NULL)
        {
            sum = sum + (temp2->data) + carry;
            temp2 = temp2->next;
        }

        carry = sum / 10;
 
        if (temp1 != NULL)
        {
            temp1->data = sum % 10;
        }
        else
        {
            struct SinglyLinkedList *newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
            newNode->data = carry;
            newNode->next = NULL;
            temp1->next = newNode;
            temp1 = newNode;
        }

        // printf("sum: %d ", sum);
        // printf("carry: %d\n", carry);
        sum = 0;
    }

    printLinkedList("resultant", *head1);

    return 0;
}

int main()
{
    struct SinglyLinkedList *head1 = NULL;
    struct SinglyLinkedList *current1 = NULL;

    takeInput("1st", &head1, &current1);

    struct SinglyLinkedList *head2 = NULL;
    struct SinglyLinkedList *current2 = NULL;

    takeInput("2nd", &head2, &current2);
    if (lengthOfLinkedList(head1) >= lengthOfLinkedList(head2))
    {
        addTwoNumbers(&head1, &head2);
    }
    else
    {
        addTwoNumbers(&head2, &head1);
    }

    // printLinkedList("1st", head1);
    // printLinkedList("2nd", head2);
    return 0;
}