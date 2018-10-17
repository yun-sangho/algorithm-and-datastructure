#include <stdio.h>

/*
 * Bubble sort 
 * [12, 3, 8, 11, 9]
 * 1st loop 4 steps for sort [12, 3, 8, 11, 9] => [3, 12, 8, 11, 9] => [3, 8, 12, 11, 9] ... => [3, 8, 11, 9, 12]
 * 2nd loop 3 steps for sort [3, 8, 11, 9, 12] => ... => [3, 8, 9, 11, 12]
 * 3rd loop 2 steps for sort [3, 8, 9, 11, 12]
 * 4th loop There is any sort in 3rd loop so the loop stops
*/

void bubbleSort(int array[], int len);
void swap(int array[], int i, int j);
void printArray(int array[], int len);

int main(void)
{
    int unsortedArray[] = {63, 21, 3, 25, 10, 98, 23, 47, 38};
    int len = sizeof(unsortedArray)/sizeof(unsortedArray[0]);

    printArray(unsortedArray, len);

    bubbleSort(unsortedArray, len);

    printArray(unsortedArray, len);
}


void bubbleSort(int array[], int len)
{
    int swap_counter = -1;

    for (int i = 0; i < len - 1; i++)
    {
        /*
         * If no elements were swapped by, it means that
         * the array is already sorted, then break the loop
        */
        if (swap_counter == 0)
        {
            break;
        }

        swap_counter = 0;

        for (int j = 0; j < len -i - 1; j++)
        {
            /*
             * If find the place to be sorted, sort value and
             * increase swap counter
            */
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swap_counter++;
            }
        }
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