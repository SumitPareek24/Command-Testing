#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
};

void takeInput(struct SinglyLinkedList ** head, struct SinglyLinkedList ** current)
{

    printf("Enter Linked List: ");
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

void printLinkedList(struct SinglyLinkedList * head) {
    printf("Linked List: ");

    while (head != NULL)
    {
        printf("%d ", &head -> data);
        printf("%d ", &head -> next);
        head = head -> next;
    }
    printf("\n");
}

int lengthOfLinkedList(struct SinglyLinkedList * head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head -> next;
    }
    return length;
}

void removeNthNode(struct SinglyLinkedList ** head, int nthNode) {
    struct SinglyLinkedList * temp = * head, * prevNode = NULL;
    int linkedListLength = lengthOfLinkedList(* head);
    if(nthNode > linkedListLength || nthNode == 0) {
        printf("Invalid position\n");
        return;
    }
    linkedListLength = linkedListLength - nthNode;
    if(linkedListLength == 0) {
        * head = (* head) -> next;
        free(temp);
        return;
    }
    
    while(linkedListLength-- && temp != NULL) {
        prevNode = temp;
        temp = temp -> next;
    }
    prevNode -> next = temp -> next;
    free(temp);
}

int main()
{
    struct SinglyLinkedList *head = NULL;
    struct SinglyLinkedList *current = NULL;

    takeInput(&head, &current);

    printf("Enter nth node: ");
    int nthNode = 0;
    scanf("%d", &nthNode);

    removeNthNode(&head, nthNode);

    printLinkedList(head);

    return 0;
}