#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int maximum = -1;

int findMaximumElements(int size, int arr[size]) {
    for(int index = 0; index < size; index++) {
        if(maximum < arr[index]) {
            maximum = arr[index];
        }
    }
    return maximum;
}

int freq[100];

void storeFrequency(int number) {
    freq[number]++;
}

int calcConsecutive(int arr[]) {
    int countMaximum = 0, currentCount = 0;
    for (int index = 0; index <= maximum; index++)
    {
        if(freq[index] == 1) {
            currentCount++;
            if(countMaximum < currentCount) {
                countMaximum = currentCount;
            }
        } else {
            currentCount = 0;
        }
    }    
    return countMaximum;
}

int main() {

    int * arr;
    arr = (int *)malloc(MAXSIZE * sizeof(int));
    int arrIndex = 0;
    printf("enter array: ");
    while (1)
    {
        int number;
        scanf("%d", &number);

        arr[arrIndex++] = number;

        char ch = getchar();
        if(ch == '\n' || ch == EOF) {
            break;
        }
    }

    findMaximumElements(arrIndex, arr);

    for (int index = 0; index < arrIndex; index++)
    {
        storeFrequency(arr[index]);
    }   

    printf("Number of maximum consecutive elements: %d\n", calcConsecutive(arr));
    free(arr);
}