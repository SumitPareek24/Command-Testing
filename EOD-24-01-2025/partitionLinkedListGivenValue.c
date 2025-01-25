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
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

struct SinglyLinkedList * rotateLinkedList(struct SinglyLinkedList * head, int valueToSeparate) {
    struct SinglyLinkedList * head1 = NULL, * tail1 = head1;
    struct SinglyLinkedList * head2 = NULL, * tail2 = head2;
    struct SinglyLinkedList * head3 = NULL, * tail3 = head3;

    while (head != NULL)
    {
        if(head -> data < valueToSeparate) {
            if(head1 == NULL) {
                head1 = head;
                tail1 = head;
            } else {
                tail1 -> next = head;
                tail1 = tail1 -> next;
            }
        } else if(head -> data == valueToSeparate) {
            if(head2 == NULL) {
                head2 = head;
                tail2 = head;
            } else {
                tail2 -> next = head;
                tail2 = tail2 -> next;
            }
        } else {
            if(head3 == NULL) {
                head3 = head;
                tail3 = head;
            } else {
                tail3 -> next = head;
                tail3 = tail3 -> next;
            }
        }
        head = head -> next;
    }

    if(tail1 != NULL) tail1 -> next = head2;
    if(tail2 != NULL) tail2 -> next = head3;
    if(tail3 != NULL) tail3 -> next = NULL;
    return head1 != NULL ? head1 : head2 != NULL ? head2 : head3;
}

int main()
{
    struct SinglyLinkedList *head = NULL;
    struct SinglyLinkedList *current = NULL;

    takeInput(&head, &current);

    printf("Enter value to separate: ");
    int valueToSeparate = 0;
    scanf("%d", &valueToSeparate);

    struct SinglyLinkedList * ans = rotateLinkedList(head, valueToSeparate);

    printLinkedList(ans);

    free(head);

    return 0;
}