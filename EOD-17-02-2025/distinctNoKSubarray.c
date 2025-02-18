#include <stdio.h>
#include <stdlib.h>

int countFrequency(int k, int arr[], int arraySize) {

    int freq[arraySize];

    for (int index = 0; index < k; index++)
    {
        freq[index] = 0;
    }

    int count = 0;

    for (int index = 0; index < k; index++)
    {
        if(freq[arr[index] - 1] == 0) {
            count++;
        }
        freq[arr[index] - 1]++;
    }

    free(freq);
    return count;
}

int main() {

    int * array;
    array = (int *)malloc(100 * sizeof(int));
    int arrayIndex = 0;
    printf("Enter array: ");
    while (1)
    {
        int number;
        scanf("%d", &number);
        array[arrayIndex++] = number;

        char ch = getchar();
        if(ch == '\n' || ch == EOF) {
            break;
        }
    }

    printf("Enter size of subarray: ");
    int subArrSize;
    scanf("%d", &subArrSize);

    int resultArray[arrayIndex - subArrSize + 1];
    int resultArrayIndex = 0;
   
    for(int firstIndex = 0; firstIndex < arrayIndex - subArrSize + 1; firstIndex++) {
        int tempArr[subArrSize];
        int l = firstIndex;
        for (int secondIndex = 0; secondIndex < subArrSize; secondIndex++)
        {
            tempArr[secondIndex] = array[l++];
        }

        resultArray[resultArrayIndex++] = countFrequency(subArrSize, tempArr, arrayIndex);
    }
    
    printf("result: ");
    for (int index = 0; index < resultArrayIndex; index++)
    {
        printf("%d ", resultArray[index]);
    }
    

    free(array);

    return 0;
}