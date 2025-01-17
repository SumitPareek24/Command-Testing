#include <stdio.h>

void merge(char *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i = 0, j = 0, k = left;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++) {
        leftArr[i] = arr[k++];
    }

    for (j = 0; j < n2; j++) {
        rightArr[j] = arr[k++];
    }

    i = 0, j = 0, k = left;

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

void mergeSort(char *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void sort2DArray(char arr[3][5]) {
    // Sorting each row of the 2D array
    for (int i = 0; i < 3; i++) {
        mergeSort(arr[i], 0, 4);  // Each row is treated as a 1D array
    }
}

int main()
{
    // 2D array with 3 rows and 5 columns
    char arr[3][5] = {
        {'g', 'r', 'a', 'p', 'w'},
        {'n', 'b', 'i', 'r', 'j'},
        {'o', 'm', 'e', 't', 's'}
    };

    sort2DArray(arr);

    // Print the sorted 2D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
