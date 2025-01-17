#include <stdio.h>

void printMat(int matSize, int mat[matSize][matSize])
{
    for (int r = 0; r < matSize; r++)
    {
        for (int c = 0; c < matSize; c++)
        {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
}

void leftRotate(int matSize, int mat[matSize][matSize])
{
    printf("Enter K:-- ");
    int k = 0;
    scanf("%d", &k);
    k = k % matSize;

    for (int i = 0; i < k; i++)
    {
        for (int idx = 0; idx < matSize; idx++)
        {
            int p = mat[idx][0];

            for (int j = 1; j < matSize; j++)
            {
                mat[idx][j - 1] = mat[idx][j];
            }

            mat[idx][matSize - 1] = p;
        }
    }

    printMat(matSize, mat);
}

void rightRotate(int matSize, int mat[matSize][matSize])
{
    printf("Enter K:-- ");
    int k = 0;
    scanf("%d", &k);
    k = k % matSize;

    for (int i = 0; i < k; i++)
    {
        for (int idx = 0; idx < matSize; idx++)
        {
            int p = mat[idx][matSize - 1];
            for (int j = matSize - 1; j > 0; j--)
            {
                mat[idx][j] = mat[idx][j - 1];
            }

            mat[idx][0] = p;
        }
    }

    printMat(matSize, mat);
}

void topRotate(int matSize, int mat[matSize][matSize])
{
    printf("Enter K:-- ");
    int k = 0;
    scanf("%d", &k);
    k = k % matSize;

    for (int i = 0; i < k; i++)
    {
        for (int idx = 0; idx < matSize; idx++)
        {
            int p = mat[0][idx];

            for (int j = 1; j < matSize; j++)
            {
                mat[j - 1][idx] = mat[j][idx];
            }

            mat[matSize - 1][idx] = p;
        }
    }

    printMat(matSize, mat);
}

void bottomRotate(int matSize, int mat[matSize][matSize])
{
    printf("Enter K:-- ");
    int k = 0;
    scanf("%d", &k);

    k = k % matSize;

    for (int i = 0; i < k; i++)
    {

        int temp[matSize];
        for (int j = 0; j < matSize; j++)
        {
            temp[j] = mat[matSize - 1][j];
        }

        for (int r = matSize - 1; r > 0; r--)
        {
            for (int c = 0; c < matSize; c++)
            {
                mat[r][c] = mat[r - 1][c];
            }
        }

        for (int c = 0; c < matSize; c++)
        {
            mat[0][c] = temp[c];
        }
    }

    printMat(matSize, mat);
}

int main()
{
    int matSize = 0;
    printf("Enter the Size :-- ");
    scanf("%d", &matSize);
    int mat[matSize][matSize];
    printf("Enter the matrix:--\n");
    for (int r = 0; r < matSize; r++)
    {
        for (int c = 0; c < matSize; c++)
        {
            scanf("%d", &mat[r][c]);
        }
    }

    while (1)
    {
        printf("Enter your Choice:-\n");
        printf("1. Left Rotate\n");
        printf("2. Right Rotate\n");
        printf("3. Top Rotate\n");
        printf("4. Bottom Rotate\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            leftRotate(matSize, mat);
            break;

        case 2:
            rightRotate(matSize, mat);
            break;

        case 3:
            topRotate(matSize, mat);
            break;

        case 4:
            bottomRotate(matSize, mat);
            break;

        default:
            printf("Please Enter Correct Choice!!!\n");
            return 0;
        }
    }
}