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

int lengthOfLinkedList(struct SinglyLinkedList * head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head -> next;
    }
    return length;
}

struct SinglyLinkedList * returnTail(struct SinglyLinkedList * head) {
    while(head -> next != NULL) {
        head = head -> next;
    }
    return head;
}

struct SinglyLinkedList * rotateLinkedList(struct SinglyLinkedList * head, struct SinglyLinkedList * tail, 
                                            int valueToRotate) {

    if(valueToRotate == 0 || head == NULL || head -> next == NULL) {
        return head;
    }

    tail -> next = head;
    tail = head;
    
    struct SinglyLinkedList * tempPtr = head;
    for(int index = 1; index < valueToRotate; index++) {
        tail = tail -> next;
    }
    head = tail -> next;
    tail -> next = NULL;
    return head;
}

int main()
{
    struct SinglyLinkedList *head = NULL;
    struct SinglyLinkedList *current = NULL;

    takeInput(&head, &current);

    printf("Enter value of K to rotate: ");
    int valueToRotate = 0;
    scanf("%d", &valueToRotate);

    int linkedListLength = lengthOfLinkedList(head);
    valueToRotate = valueToRotate % linkedListLength;

    struct SinglyLinkedList * tail = returnTail(head);

    struct SinglyLinkedList * ans = rotateLinkedList(head, tail, valueToRotate);

    printLinkedList(ans);

    free(head);

    return 0;
}