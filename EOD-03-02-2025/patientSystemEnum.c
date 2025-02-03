#include <stdio.h>
#include <stdlib.h>

typedef enum severity {
    Stable, Serious, Critical
} severity;

struct Node {
    int uniqueId;
    severity severity;
    struct Node * next;
};

char *severityName[3];

int stringCmp(char *string1, char *string2)
{
    while (*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 != *string2)
            return (*string1 - *string2);
        string1++;
        string2++;
    }
    return (*string1 - *string2);
}

void takeInput(int noOfPatients, struct Node ** head, struct Node ** current) {    

    printf("Enter id & status: \n");
    while(noOfPatients) {
        char * status = (char *)malloc(10 * sizeof(char));
        int id;

        scanf("%d", &id);

        scanf("%s", status);
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode -> uniqueId = id;

        if(stringCmp(status, "Critical") == 0) {
            newNode -> severity = Critical;
        } else if(stringCmp(status, "Serious") == 0) {
            newNode -> severity = Serious;
        } else if(stringCmp(status, "Stable") == 0) {
            newNode -> severity = Stable;
        } else {
            printf("\nInvalid severity\n");
        }
        
        newNode -> next = NULL;

        if(* head == NULL) {
            * head = newNode;
            * current = newNode;
        } else {
            (* current) -> next = newNode;
            * current = newNode;
        }
        noOfPatients--;
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

struct Node * merge2SortedLinkedList(struct Node * leftHead, struct Node * rightHead) {
    struct Node * tempEnd = NULL, * tempHead = NULL;

    if(leftHead -> severity >= rightHead -> severity) {
        tempHead = tempEnd = leftHead;
        leftHead = leftHead -> next;
    } else {
        tempHead = tempEnd = rightHead;
        rightHead = rightHead -> next;
    }

    while (leftHead != NULL && rightHead != NULL) 
    {
        if(leftHead -> severity >= rightHead -> severity) {
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
    } else {
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

void printList(struct Node * head) {
    printf("Sorted data:\n");
    while(head != NULL) {
        printf("Id: %d severity: %s\n", head -> uniqueId, severityName[head -> severity]);
        head = head -> next;
    }
}

void createSeverityArray() {
    severityName[0] = "Stable";
    severityName[1] = "Serious";
    severityName[2] = "Critical";
}

int main() {

    struct Node * head = NULL, * current = NULL;
    int noOfPatients;
    printf("Enter no of patients: ");
    scanf("%d", &noOfPatients);
    createSeverityArray();
    takeInput(noOfPatients, &head, &current);
    head = mergeSort(head);
    printList(head);

    return 0;
}