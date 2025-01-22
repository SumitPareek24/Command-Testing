#include <stdio.h>

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
    struct SinglyLinkedList *bottom;
};

struct SinglyLinkedList *merge2List(struct SinglyLinkedList *list1, struct SinglyLinkedList *list2)
{
    struct SinglyLinkedList *headResultantNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
    struct SinglyLinkedList *resultantNode = headResultantNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            resultantNode->bottom = list1;
            resultantNode = list1;
            list1 = list1->bottom;
        }
        else
        {
            resultantNode->bottom = list2;
            resultantNode = list2;
            list2 = list2->bottom;
        }
    }

    if (list1)
    {
        resultantNode->bottom = list1;
    }
    else
    {
        resultantNode->bottom = list2;
    }

    if (resultantNode->bottom)
    {
        resultantNode->bottom->next = NULL;
    }
    return headResultantNode->bottom;
}

struct SinglyLinkedList *flatten(struct SinglyLinkedList *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }

    struct SinglyLinkedList *mergedHead = flatten(root->next);
    root = merge2List(root, mergedHead);
    return root;
}

int main() {

    struct SinglyLinkedList * head;
    flatten(head);

    return 0;
}