#include <stdio.h>
#define MAXSIZE 100

typedef struct Stack
{
    int arr[MAXSIZE];
    int top;
} Stack;

typedef struct Queue
{
    Stack stack;
    int front;
} Queue;

void push(Stack * stack, int value) {

    if(stack -> top >= MAXSIZE) {
        printf("Queue overflow\n");
        return;
    }

    stack -> arr[(stack -> top)] = value;
    stack -> top++;
}

void enqueue(Queue * q) {
    int value;
    printf("enter value: ");
    scanf("%d", &value);

    if(q -> front == 0) {
        q -> front = value;
    }

    push(&q -> stack, value);
}

int isEmpty(Stack * stack) {
    if(stack -> top == 0)  {
        return 1;
    }
    return 0;
}

int top(Stack * stack) {
    return stack -> arr[stack -> top - 1];
}

int pop(Stack * stack) {
    if(stack -> top <= 0) {
        printf("\nQueue underflow\n\n");
        return 0;
    }
    int popValue = top(stack);
    stack -> top--;

    if(isEmpty(stack)) {
        return popValue;
    }

    int item = pop(stack);
    push(stack, popValue);
    return item;
}

void dequeue(Queue * q) {
    int removedValue = pop(&q -> stack);
    printf("The removed value is: %d\n", removedValue);

    if(!isEmpty(&q -> stack)) {
        q -> front = q -> stack.arr[0];
    }
}

int peek(Queue * q) {
    return q -> front;
}

int main() {
    Queue * q;
    q -> front = 0;
    q -> stack.top = 0;
    int choice;
    while (1)
    {   
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue(q);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                printf("\npeek: %d\n\n", peek(q));
                break;

            case 4:
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("\nInvalid\n\n");
                break;
        }
    }
    

    return 0;
}
