#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int freq[MAXSIZE] = {0};

int storeNoInSet(int number)
{
    freq[number]++;
}

void removeElements(int number)
{
    freq[number]--;
}

int countDistinctElements()
{
    int count = 0;
    for (int index = 0; index < MAXSIZE; index++)
    {
        if (freq[index] > 0)
        {
            count++;
        }
    }
    return count;
}

void resetFreq()
{
    for (int index = 0; index < MAXSIZE; index++)
    {
        freq[index] = 0;
    }
}

int ans;

void func(int size, int arr[size], int noOfDiffElements)
{
    for (int firstIndex = 0; firstIndex < size; firstIndex++)
    {
        resetFreq();
        storeNoInSet(arr[firstIndex]);
        for (int secondIndex = firstIndex + 1; secondIndex < size; secondIndex++)
        {
            storeNoInSet(arr[secondIndex]);
            int count = countDistinctElements();

            if (count == noOfDiffElements)
            {
                ans++;
            }
            else if (count > noOfDiffElements)
            {
                removeElements(arr[secondIndex]);
                break;
            }
        }
        removeElements(arr[firstIndex]);
    }
}

int main()
{

    int *arr;
    arr = (int *)malloc(MAXSIZE * sizeof(int));
    printf("Enter array: ");
    int index = 0;
    while (1)
    {
        int number;
        scanf("%d", &number);

        arr[index++] = number;

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }

    int noOfDiffElements;
    printf("Enter no of distinct elements required: ");
    scanf("%d", &noOfDiffElements);

    func(index, arr, noOfDiffElements);

    printf("Ans: %d\n", ans);

    free(arr);

    return 0;
}