#include <stdio.h>
#include <stdlib.h>

int takeInput(int * arr) {
    int arraySize = 0;
    printf("Enter array elements: ");
    while(1) {  
        int number;
        if(scanf("%d", &number)) {
            arr[arraySize++] = number;
        } else {
            break;
        }
        char character = getchar();
        if(character == '\n' || character == EOF) {
            break;
        }
    }
    return arraySize;
}

void findZerosIndex(int * arr, int size, int noOfFlip) {
    int * zerosIndexArray = (int *)calloc(100, sizeof(int));
    int zerosIndex = 0;
    for(int arrayIndex = 0; arrayIndex < size; arrayIndex++) {
        if(arr[arrayIndex] == 0) {
            zerosIndexArray[zerosIndex++] = arrayIndex;
        }
    }

    int maximumOnes = -1;

    for(int index = 1; index < zerosIndex - noOfFlip; index++) {
        int temp1 = zerosIndexArray[index - 1] + 1;
        int temp2 = zerosIndexArray[index + noOfFlip] - 1;
        if(maximumOnes < (temp2 - temp1)) {
            maximumOnes = temp2 - temp1 + 1;
        }
    }
    printf("maximum ones: %d\n", maximumOnes);
}

int main() {

    int * arr = (int *)malloc(100 * sizeof(int));
    int arraySize = takeInput(arr);

    int noOfFlip = 0;
    printf("Enter no of flip: ");
    scanf("%d", &noOfFlip);

    findZerosIndex(arr, arraySize, noOfFlip);    

    return 0;
}