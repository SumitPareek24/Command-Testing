#include <stdio.h>
#include <stdlib.h>
#define MAPSIZE 26

int map[MAPSIZE];

void insertInMap(char word)
{
    int index = word - 'a';
    map[index]++;
}

void removeFromMap(char word)
{
    int index = word - 'a';
    map[index]--;
}

int sizeOfMap()
{
    int count = 0;
    for (int index = 0; index < MAPSIZE; index++)
    {
        if (map[index] != 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char *str;
    str = (char *)malloc(100 * sizeof(char));

    printf("Enter string: ");
    scanf("%[^\n]", str);

    printf("Enter K: ");
    int kDifferentChar;
    scanf("%d", &kDifferentChar);

    int maximumLength = -1;
    int secondIndex = 0;
    for (int firstIndex = 0; str[firstIndex] != '\0'; firstIndex++)
    {
        insertInMap(str[firstIndex]);

        while(sizeOfMap() > kDifferentChar)
        {
            removeFromMap(str[secondIndex]);
            secondIndex++;
        }

        int currentLength = firstIndex - secondIndex + 1;
        maximumLength = (currentLength > maximumLength) ? currentLength : maximumLength;
    }

    printf("Maximum: %d\n", maximumLength);

    free(str);

    return 0;
}