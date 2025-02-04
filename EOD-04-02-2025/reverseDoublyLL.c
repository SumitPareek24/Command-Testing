#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next, * prev;
};

void takeInput(struct Node ** head, struct Node ** current) {
    printf("enter linked list: ");
    while (1)
    {
        int data;
        scanf("%d", &data);

        struct Node * newNode = (struct Node * )malloc(sizeof(struct Node));
        newNode -> data = data;
        newNode -> next = NULL;
        newNode -> prev = NULL;

        if(* head == NULL) {
            * head = newNode;
            (* head) -> prev = NULL;
            * current = newNode;
        } else {
            (* current) -> next = newNode;
            newNode -> prev = * current;
            * current = (* current) -> next;
        }

        char ch = getchar();
        if(ch == '\n' || ch == EOF) {
            break;
        }
    }
}

void reverseDoublyLL(struct Node** head) {
    struct Node* traverse = * head;
    while (traverse != NULL)
    {
        struct Node* temp = traverse -> prev;
        traverse -> prev = traverse -> next;
        traverse -> next = temp;
        * head = traverse;
        traverse = traverse -> prev;
    }
}

void printLL(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }  
    printf("\n");
}

int main() {
    struct Node * head = NULL, * current = NULL;
    takeInput(&head, &current);
    reverseDoublyLL(&head);
    printLL(head);

    return 0;
}