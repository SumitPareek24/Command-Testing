#include <stdio.h>
#define MAXSIZE 100

typedef struct priorityQueue
{
    int queue[MAXSIZE];
    int rear;
    int front;
} priorityQueue;

void insert(priorityQueue * queue, int element) {
    int i;
    for(i = queue -> rear - 1; i >= 0; i--) {
        if(queue -> queue[i] < element) {
            break;
        }
        queue -> queue[i + 1] = queue -> queue[i];
    }
    queue -> queue[i + 1] = element;
    queue -> rear++;
}

void display(priorityQueue * queue) {
    printf("Queue: ");
    for(int i = queue -> front; i < queue -> rear; i++) {
        printf("%d ", queue -> queue[i]);
    }
    printf("\n");
}

void pop(priorityQueue * queue) {
    printf("Popped element is: %d\n", queue -> queue[queue -> rear - 1]);
    queue -> rear--;
}

int main() {

    priorityQueue * queue;
    queue -> front = 0;
    queue -> rear = 0;

    int choice;
    int element;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter element: ");
            scanf("%d", &element);
            insert(queue, element);
            break;

        case 2:
            pop(queue);
            break;
        
        case 3:
            display(queue);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            break;
        }
    }
}