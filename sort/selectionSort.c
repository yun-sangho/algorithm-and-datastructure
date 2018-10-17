#include <stdio.h>

/*
 * Selection sort 
 * [12, 3, 8, 11, 9]
 * 1st loop Find the number for first index by iterating the array and put it on the first index
 * 2nd loop Find the number for second index by iterating the array loop and put it on the second index
 * 3rd loop Find the number for third index by iterating the array loop and put it on the third index
 * 4th loop Find the number for fourth index by iterating the array loop and put it on the fourth index
*/

void selectionSort(int array[], int len);
void swap(int array[], int i, int j);
void printArray(int array[], int len);

int main(void)
{
    int unsortedArray[] = {63, 21, 3, 25, 10, 98, 23, 47, 38};
    int len = sizeof(unsortedArray)/sizeof(unsortedArray[0]);

    printArray(unsortedArray, len);

    selectionSort(unsortedArray, len);

    printArray(unsortedArray, len);
}

void selectionSort(int array[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        // Find minimum value through out the loop
        for (int j = i + 1; j < len; j++)
        {
            int mininum_index = i;
            if (array[mininum_index] > array[j])
            {
                mininum_index = j;
            }
        }
        // Swap the minimum value founded through out the loop with
        // the first element in the loop.
        swap(&array[smallestNumberIndex], &array[i]);
    }
}

void swap(int *i, int *j)
{
    // if two elements are same, don't have to swap
    if (*i == *j)
    {
        return;
    }

    int temp = *i;
    *i = *j;
    *j = temp;
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