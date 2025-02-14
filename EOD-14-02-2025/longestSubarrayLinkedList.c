#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    int prefixSum;
    struct Node * next;
} Node ;

Node ** hashmap;
int size;

int maximumNumber(int n1, int n2)
{
    return n1 >= n2 ? n1 : n2;
}

void insertInHashmap(int index, int prefixSum) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> next = NULL;
    newNode -> index = index;
    newNode -> prefixSum = prefixSum;
    hashmap[size++] = newNode;
}

int searchKey(int index, int prefixSum) {

    for (int i = 0; i < size; i++)
    {
        if(hashmap[i] -> prefixSum == prefixSum) {
            return hashmap[i] -> index;
        }
    }
    
    return -1;
}

void displayHashmap() {
    printf("Hash map: \n");
    for(int i = 0; i < size; i++) {
        printf("index: %d ", hashmap[i] -> index);
        printf("prefix sum: %d ", hashmap[i] -> prefixSum);
        printf("\n");
    }
}

int calculateAns(int size, int arr[])
{
    int currentPrefixSum = 0;
    int ans = -1;

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

        int searchIndex = searchKey(index, currentPrefixSum);
        if(searchIndex >= 0) {
            ans = maximumNumber(ans, index - searchIndex);
        } else {
            insertInHashmap(index, currentPrefixSum);
        }
    }

    displayHashmap();

    printf("\n");

    return ans;
}

int main()
{
    hashmap = (Node **)calloc(1000, sizeof(Node*));
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

    free(hashmap);

    return 0;
}