#include <stdio.h>

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transposeMatrix(int n, int (*arr)[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swapNumbers(&arr[i][j], &arr[j][i]);
        }
    }
}

void antiClockWiseRotation(int n, int (*arr)[n], int k)
{
    while (k > 0)
    {
        transposeMatrix(n, arr);
        for (int i = 0; i < n; i++)
        {
            int start = 0, end = n - 1;
            while (start <= end)
            {
                swapNumbers(&arr[i][start++], &arr[i][end--]);
            }
        }
        k--;
    }

    printf("anti - clockwise matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("enter number: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("enter elements of matrix: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("original matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    while (1)
    {
        int choice;
        printf("1. For anti clockwise\n");
        printf("2. For exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            antiClockWiseRotation(n, arr, 3);
            break;

        default:
            printf("Exiting...\n");
            return 0;
        }
    }

    return 0;
}