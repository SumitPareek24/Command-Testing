#include <stdio.h>
#define MAXSIZE 100

typedef struct Stack
{
    int arr[MAXSIZE];
    int top;
} Stack;

typedef struct Queue
{
    Stack inputStack, outputStack;
    int size;
} Queue;

void push(Stack * s, int value) {

    if(s -> top >= MAXSIZE) {
        printf("Stack overflow\n");
        return;
    }

    s -> arr[s -> top] = value;
    s -> top++;
}

void enqueue(Queue * q) {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    push(&q -> inputStack, value);
    q -> size++;
}

int isStackEmpty(Stack stack) {
    if(stack.top == 0) {
        return 1;
    }
    return 0;
}

void pop(Stack * stack) {
    if(stack -> top <= 0) {
        printf("Stack underflow\n");
        return;
    }
    stack -> top--;
}

int top(Stack stack) {
    if(stack.top == 0) {
        return -1;
    }
    return stack.arr[stack.top - 1];
}

void dequeue(Queue * q) {
    if(isStackEmpty(q -> outputStack)) {
        while (isStackEmpty(q -> inputStack) == 0) {
            int value = top(q -> inputStack);
            push(&q -> outputStack, value);
            pop(&q -> inputStack);
        }    
    }    

    int value = top(q -> outputStack);
    pop(&q -> outputStack);
    printf("Dequeued value is: %d\n", value);

    q -> size--;
}

int peek(Queue * q) {
    if(isStackEmpty(q -> outputStack)) {
        while (!isStackEmpty(q -> inputStack))
        {   
            int value = top(q -> inputStack);
            pop(&q -> inputStack);
            push(&q -> outputStack, value);
        }
    }
    int value = top(q -> outputStack);
    return value;
}

int main() {

    Queue q;
    q.inputStack.top = 0;
    q.outputStack.top = 0;
    q.size = 0;

    int choice;

    while (1)
    {   
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;

        case 2:
            dequeue(&q);
            break;

        case 6:
            printf("Exiting\n");
            return 0;
        
        default:
            break;
        }
    }

    return 0;
}