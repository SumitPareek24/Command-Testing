#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
};

void takeInput(char * linkedListNo, struct SinglyLinkedList ** head, struct SinglyLinkedList ** current)
{

    printf("Enter %s Linked List: ", linkedListNo);
    while (1)
    {
        int number;
        scanf("%d", &number);
        struct SinglyLinkedList * newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
        newNode -> data = number;
        newNode -> next = NULL;

        if (* head == NULL)
        {
            * head = newNode;
        }
        else
        {
            (* current) -> next = newNode;
        }

        * current = newNode;

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
}

void printLinkedList(char * linkedListNo, struct SinglyLinkedList * head) {
    printf("%s Linked List: ", linkedListNo);

    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void merge2SortedLinkedList(struct SinglyLinkedList * head1, struct SinglyLinkedList * head2) {
    struct SinglyLinkedList * temp = NULL, * temp2 = NULL;

    if(head1 -> data  <= head2 -> data) {
        temp = temp2 = head1;
        head1 = head1 -> next;
    } else {
        temp = temp2 = head2;
        head2 = head2 -> next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if(head1 -> data <= head2 -> data) {
            temp2 -> next = head1;
            temp2 = head1;
            head1 = head1 -> next;
        } else {
            temp2 -> next = head2;
            temp2 = head2;
            head2 = head2 -> next;
        }
    }    

    if(head1 != NULL) {
        temp2 -> next = head1;
    } else {
        temp2 -> next = head2;
    }

    printLinkedList("merged", temp);
}

int main()
{

    struct SinglyLinkedList *head1 = NULL;
    struct SinglyLinkedList *current1 = NULL;

    takeInput("1st", &head1, &current1);

    struct SinglyLinkedList * head2 = NULL;
    struct SinglyLinkedList * current2 = NULL;

    takeInput("2nd", &head2, &current2);

    merge2SortedLinkedList(head1, head2);

    return 0;
}