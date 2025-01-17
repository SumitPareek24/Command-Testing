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

void flatten2DArray(char arr[3][5], char *flatArr, int rows, int cols) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flatArr[index++] = arr[i][j];
        }
    }
}

void reconstruct2DArray(char *flatArr, char arr[3][5], int rows, int cols) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = flatArr[index++];
        }
    }
}

void sortEntire2DArray(char arr[3][5], int rows, int cols) {
    char flatArr[rows * cols];
    flatten2DArray(arr, flatArr, rows, cols);

    mergeSort(flatArr, 0, rows * cols - 1);

    reconstruct2DArray(flatArr, arr, rows, cols);
}

int main()
{
    char arr[3][5] = {
        {'g', 'r', 'a', 'p', 'w'},
        {'n', 'b', 'i', 'r', 'j'},
        {'o', 'm', 'e', 't', 's'}
    };

    sortEntire2DArray(arr, 3, 5);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
