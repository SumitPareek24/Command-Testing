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
    int arrow = 0;

    while (head != NULL)
    {   
        if(arrow) printf(" -> ");
        printf("%d", head->data);
        head = head->next;
        arrow = 1;
    }
    printf("\n");
}

void oddEvenList(struct SinglyLinkedList ** head)
{
    if(* head == NULL || (* head) -> next == NULL) {
        return;
    }
    struct SinglyLinkedList * oddTail = * head, * oddHead = NULL;
    struct SinglyLinkedList * evenTail = * head, * evenHead = NULL;
    struct SinglyLinkedList * currentNode = * head;
    while(currentNode != NULL) {
        struct SinglyLinkedList * nextNode = currentNode -> next;
        if(currentNode -> data % 2 == 0) {
            if(evenHead == NULL) {
                evenHead = currentNode;
                evenTail = evenHead;
            } else {
                evenTail -> next = currentNode;
                evenTail = evenTail -> next;
            }   
        } else {
            if(oddHead == NULL) {
                oddHead = currentNode;
                evenTail = oddHead;
            } else {
                oddTail -> next = currentNode;
                oddTail = oddTail -> next;
            }
        }
        currentNode -> next = NULL;
        currentNode = nextNode;
    }

    if(oddTail != NULL) {
        oddTail -> next = evenHead;
        * head = oddHead;
    } else {
        * head = evenHead;
    }

    oddTail -> next = evenHead;
}

int main()
{
    struct SinglyLinkedList *head = NULL;
    struct SinglyLinkedList *current = NULL;

    takeInput("1st", &head, &current);
    oddEvenList(&head);
    printLinkedList("odd-even", head);

    return 0;
}