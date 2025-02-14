#include <stdio.h>
#include <stdlib.h>

int checkExist(int freq[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (freq[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int maximumNumber(int n1, int n2)
{
    return n1 >= n2 ? n1 : n2;
}

int calculateAns(int size, int arr[])
{
    int freqArray[2 * size + 1];
    int currentPrefixSum = 0;
    int ans = -1;

    for (int index = 0; index < 2 * size + 1; index++)
    {
        freqArray[index] = -1;
    }

    for (int index = 0; index < size; index++)
    {
        if (arr[index] == 0)
        {
            currentPrefixSum--;
        }
        else
        {
            currentPrefixSum++;
        }

        if (currentPrefixSum == 0)
        {
            ans = index + 1;
        }

        int positiveIndex = currentPrefixSum + size;

        if (freqArray[positiveIndex] != -1)
        {
            ans = maximumNumber(ans, (index - freqArray[positiveIndex]));
            printf("ans: %d\n", ans);
        }
        else
        {
            freqArray[positiveIndex] = index;
        }
    }

    for(int i = 0; i < 2 * size + 1; i++) {
        printf("%d ", freqArray[i]);
    }
    printf("\n");

    return ans;
}

int main()
{

    int *arr;
    arr = (int *)malloc(sizeof(int) * 100);
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

    int ans = calculateAns(index, arr);

    if (ans == -1)
    {
        printf("0\n");
    }
    else
    {
        printf("maximum length subarray: %d\n", ans);
    }

    return 0;
}