#include <stdio.h>
#include <stdlib.h>

void pushElementIntoStack(int * top, int * stack, int size) {
    int data;
    printf("enter element: ");
    scanf("%d", &data);

    if((* top) == size - 1) {
        printf("\nStack overflow\n\n");
        return;
    }
    (* top)++;
    stack[(* top)] = data;    
}

void popElementFromStack(int * top, int * stack, int size) {
    if((* top) == -1) {
        printf("\nStack underflow\n\n");
        return;
    }

    int item = stack[(* top)];
    printf("%d removed from stack\n", (* top));
    (* top)--;
}

void topElementOfStack(int * top, int * stack, int size) {
    if((* top) == -1) {
        printf("\nNo element present in the stack\n\n");
        return;
    }

    printf("Top element: %d\n", stack[(* top)]);
}

void displayStack(int * top, int * stack, int size) {
    if((* top) == -1) {
        printf("\nNo element present in the stack\n\n");
        return;
    }
    printf("Stack elements: ");
    for(int index = (* top); index >= 0; index--) {
        printf("%d ", stack[index]);
    }
    printf("\n");
}

int main() {

    int * stack = (int *)malloc(100 * sizeof(int));

    int sizeOfStack;
    printf("Enter size of stack: ");
    scanf("%d", &sizeOfStack);
    stack = realloc(stack, sizeOfStack * sizeof(int));

    int choice;
    int top = -1;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                pushElementIntoStack(&top, stack, sizeOfStack);
                break;
            
            case 2:
                popElementFromStack(&top, stack, sizeOfStack);
                break;

            case 3:
                topElementOfStack(&top, stack, sizeOfStack);
                break;

            case 4: 
                displayStack(&top, stack, sizeOfStack);
                break;
            
            default:
                printf("Exiting...\n");
                return 0;
        }
    }
    
    free(stack);

    return 0;
}