#include <stdio.h>

void linear_search(int array[], int len, int value);
void printArray(int array[], int len);

int main(void)
{
    int array[] = {63, 21, 3, 25, 10, 98, 23, 47, 38};
    int len = sizeof(array)/sizeof(array[0]);

    printArray(array, len);

    linear_search(array, len, 10);

    printArray(array, len);
}

int linear_search(int array[], int len, int value)
{
    int index = -1;

    // Find the loop by iterating array one by one
    for (int i = 0; i < len; i++)
    {
        if (array[i] == target)
        {
            index = i;
            break;
        }
    }

    // If find element,
    if (index == -1)
    {
        printf("There is not %i in the array\n", target);
        return 0;
    }

    // Otherwise
    printf("%i is %ith value in the array\n", target, index);
    return 1;
}

void printArray(int array[], int len)
{
    printf("Array: ");

    for (int x = 0; x < len; x ++)
    {
        printf("%i ", array[x]);
    }

    printf ("\n");
}