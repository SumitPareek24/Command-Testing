#include <stdio.h>
#include <stdlib.h>

struct Node {
    char * str;
    struct Node * next;
};

void takeInput(struct Node ** head, struct Node ** current) {
    printf("Enter name: ");
    while (1)
    {
        char * name = (char *)malloc(sizeof(char) * 20);
        scanf("%s", name);

        struct Node * newNode = (struct Node * )malloc(sizeof(struct Node));
        newNode -> str = name;
        newNode -> next = NULL;

        if(* head == NULL) {
            * head = newNode;
            * current = newNode;
        } else {
            (* current) -> next = newNode;
            * current = newNode;
        }

        char ch = getchar();
        if(ch == '\n' || ch == EOF) {
            break;
        }
    }    
}

struct Node * findMiddle(struct Node * head) {
    struct Node * slow = head, * fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int stringCmp(char * str1, char * str2) {
    while(* str1 != '\0' && * str2 != '\0') {
        if(* str1 != * str2) {
            return (* str1) - (* str2);
        }
        str1++;
        str2++;
    }
    return (* str1) - (* str2);
}

struct Node * merge2SortedList(struct Node * leftHead, struct Node * rightHead) {
    struct Node * tempHead = NULL, * tempEnd = NULL;

    if(stringCmp(leftHead -> str, rightHead -> str) < 0) {
        tempEnd = tempHead = leftHead;
        leftHead = leftHead -> next;
    } else if(stringCmp(leftHead -> str, rightHead -> str) > 0) {
        tempEnd = tempHead = rightHead;
        rightHead = rightHead -> next;
    }

    while(leftHead && rightHead) {
        if(stringCmp(leftHead -> str, rightHead -> str) < 0) {
            tempEnd -> next = leftHead;
            tempEnd = leftHead;
            leftHead = leftHead -> next;
        } else if(stringCmp(leftHead -> str, rightHead -> str) > 0) {
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
    
    return merge2SortedList(leftHead, rightHead);
}

int main() {

    struct Node * head = NULL, * current = NULL;
    takeInput(&head, &current);

    struct Node * sortedHead = mergeSort(head);
    int check = 0;
    while(sortedHead != NULL) {
        if(check)
            printf(" -> ");
        printf("%s", sortedHead -> str);
        sortedHead = sortedHead -> next;
        check = 1;
    }

    return 0;
}