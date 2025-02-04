#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
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

        if(* head == NULL) {
            * head = newNode;
            * current = newNode;
        } else {
            (* current) -> next = newNode;
            * current = (* current) -> next;
        }

        char ch = getchar();
        if(ch == '\n' || ch == EOF) {
            break;
        }
    }
}

struct Node * findMiddle(struct Node * head) {

    struct Node * slow = head, * fast = head -> next;
    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

struct Node * merge2SortedLinkedList(struct Node * leftHead, struct Node * rightHead) {
    struct Node * tempHead = NULL, * tempEnd = NULL;

    if(leftHead -> data <= rightHead -> data) {
        tempHead = tempEnd = leftHead;
        leftHead = leftHead -> next;
    } else {
        tempHead = tempEnd = rightHead;
        rightHead = rightHead -> next;
    }

    while(leftHead && rightHead) {
        if(leftHead -> data <= rightHead -> data) {
            tempEnd -> next = leftHead;
            tempEnd = leftHead;
            leftHead = leftHead -> next;
        } else {
            tempEnd -> next = rightHead;
            tempEnd = rightHead;        
            rightHead = rightHead -> next;
        }
    }

    if(leftHead != NULL) {
        tempEnd -> next = leftHead;
    }

    if(rightHead != NULL) {
        tempEnd -> next = rightHead;
    }

    return tempHead;
}

struct Node * mergeSort(struct Node * head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    struct Node * middle = findMiddle(head);

    struct Node * leftHead = head;
    struct Node * rightHead = middle -> next;
    middle -> next = NULL;

    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return merge2SortedLinkedList(leftHead, rightHead);
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

    int k;
    printf("enter value of k: ");
    scanf("%d", &k);

    struct Node * tempHead = head, * tempEnd = head, * prev = NULL;
    int tempK = k;
    int count = 1;

    while(tempEnd != NULL) {
        if(count % 2 == 0) {
            int index = 0;
            while(tempEnd != NULL && index < k) {
                tempEnd = tempEnd -> next;
                prev = prev -> next;
                index++;
            }
            tempHead = tempEnd;
        } else {
            int index = 1;
            while(tempEnd != NULL && index < k) {
                tempEnd = tempEnd -> next;
                index++;
            }
            
            if(tempEnd == NULL) {
                break;
            }

            struct Node * nextSegment = tempEnd -> next;
            tempEnd -> next = NULL;
            
            tempHead = mergeSort(tempHead);

            if(prev != NULL)
            {
                prev -> next = tempHead;
            }
            else {
                head = tempHead;
            }
            
            while(tempEnd -> next != NULL)
            {
                tempEnd = tempEnd -> next;
            }
            prev = tempEnd;
            tempEnd -> next = nextSegment;
            tempHead = nextSegment;
            tempEnd = nextSegment;
        }
        count++;
    }

    printLL(head);

    return 0;
}