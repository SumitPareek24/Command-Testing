#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum priority
{
    VIP,
    SENIOR_CITIZEN,
    GENERAL
} priority;

struct passenger
{
    int id;
    priority priority;
    char *name;
};

char *priorityArray[3];

void initializeArray()
{
    priorityArray[0] = "VIP";
    priorityArray[1] = "SENIOR_CITIZEN";
    priorityArray[2] = "GENERAL";
}

void merge(struct passenger array[], int left, int mid, int right) {
    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;

    struct passenger leftArr[leftArrSize], rightArr[rightArrSize];
    int leftIndex = 0, rightIndex = 0, arrayIndex = left;

    while(leftIndex < leftArrSize) {
        leftArr[leftIndex++] = array[arrayIndex++];
    }

    while(rightIndex < rightArrSize) {
        rightArr[rightIndex++] = array[arrayIndex++];
    }

    leftIndex = 0, arrayIndex = left, rightIndex = 0;
    while(leftIndex < leftArrSize && rightIndex < rightArrSize) {
        if(leftArr[leftIndex].priority <= rightArr[rightIndex].priority) {
            array[arrayIndex] = leftArr[leftIndex];
            arrayIndex++;
            leftIndex++;
        } else {
            array[arrayIndex] = rightArr[rightIndex];
            arrayIndex++;
            rightIndex++;
        }
    }

    while(leftIndex < leftArrSize) {
        array[arrayIndex] = leftArr[leftIndex];
        arrayIndex++;
        leftIndex++;
    }

    while(rightIndex < rightArrSize) {
        array[arrayIndex] = rightArr[rightIndex];
        arrayIndex++;
        rightIndex++;
    }
}

void mergeSort(struct passenger array[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);

        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int choice;
    int noOfOperations;
    printf("Enter no of operations: ");
    scanf("%d", &noOfOperations);

    struct passenger array[noOfOperations];
    struct passenger newPassenger;

    initializeArray();
    int front = 0;
    int rear = 0;
    while (noOfOperations--)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter id: ");
            scanf("%d", &newPassenger.id);
            printf("Enter priority: ");
            char priorityStr[20];
            scanf("%s", priorityStr);

            if (strcmp(priorityStr, "VIP") == 0)
            {
                newPassenger.priority = VIP;
            }
            else if (strcmp(priorityStr, "SENIOR_CITIZEN") == 0)
            {
                newPassenger.priority = SENIOR_CITIZEN;
            }
            else if (strcmp(priorityStr, "GENERAL") == 0)
            {
                newPassenger.priority = GENERAL;
            }
            else
            {
                printf("\nInvalid severity\n");
            }

            printf("Enter name: ");
            newPassenger.name = (char *)malloc(100 * sizeof(char));
            scanf("%s", newPassenger.name);
            array[rear] = newPassenger; 
            rear++;
            mergeSort(array, front, rear - 1);
            break;

        case 2:
            if(front < rear) {
                printf("Serving Passenger: ID: %d, ", array[front].id);
                printf("Name: %s, ", array[front].name);
                printf("Type: %s\n", priorityArray[array[front].priority]);
                free(array[front].name);
                front++;
            } else {
                printf("Queue is empty\n");
            }
            break;

        case 3: 
            printf("Waiting passenger:\n");
            for(int index = front; index < rear; index++) {
                printf("ID: %d ", array[index].id);
                printf("Name: %s\n", array[index].name);
                printf("Type: %s ", priorityArray[array[index].priority]);
            }
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    for (int index = front; index < rear; index++)
    {
        free(array[index].name);
    }

    return 0;
}