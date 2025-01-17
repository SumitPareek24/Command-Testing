#include <stdio.h>

void merge(char *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i = 0, j = 0, k = left;

    int leftArr[n1], rightArr[n2];

    for(i = 0; i < n1; i++) {
        leftArr[i] = arr[k++];
    }

    for(j = 0; j < n2; j++) {
        rightArr[j] = arr[k++];
    }

    i = 0, j = 0,k=left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(char * arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{

    // int arr[] = {7, 3, 8, 32, 1, 90, 4};
    char arr[] = "grapwnbi";
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}