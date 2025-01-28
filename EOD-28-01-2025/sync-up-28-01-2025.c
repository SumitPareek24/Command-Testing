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

void merge(int * arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int leftSubArr[n1], rightSubArr[n2];

    int leftIndex = 0, rightIndex = 0, arrIndex = left;
    while(leftIndex < n1) {
        leftSubArr[leftIndex++] = arr[arrIndex++];
    }

    while(rightIndex < n1) {
        rightSubArr[rightIndex++] = arr[arrIndex++];
    }

    leftIndex = 0, rightIndex = 0, arrIndex = left;

    while(leftIndex < n1 && rightIndex < n2) {
        if(leftSubArr[leftIndex] <= rightSubArr[rightIndex]) {
            arr[arrIndex++] = leftSubArr[leftIndex++];
        } else {
            arr[arrIndex++] = rightSubArr[rightIndex++];
        }
    }

    while (leftIndex < n1)
    {
        arr[arrIndex++] = leftSubArr[leftIndex++];
    }
    
    while (rightIndex < n2)
    {
        arr[arrIndex++] = rightSubArr[rightIndex++];
    }
}

void mergeSort(int * arr, int left, int right) {
    if(left < right)  {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int findMaximumDifference(int * arr, int size) {
    int maximumDifference = -1;
    for(int index = 0; index < size - 1; index++) {
        int currentDifference = arr[index + 1] - arr[index];
        if(maximumDifference < currentDifference) {
            maximumDifference = currentDifference;
        }
    }
    return maximumDifference == -1 ? 0 : maximumDifference;
}


int main() {

    int * arr = (int *)malloc(100 * sizeof(int));
    int arraySize = takeInput(arr);

    mergeSort(arr, 0, arraySize - 1);

    int maximumDifference = findMaximumDifference(arr, arraySize);
    printf("maximum difference: %d\n", maximumDifference);

    return 0;
}