#include <stdio.h>

/*
 * Merge sort 
 *     [12, 3, 8, 11, 9]
 *    [12, 3, 8], [11, 9]
 *  [12, 3], [8], [11], [9]
 * [12], [3], [8], [11], [9]
 *  [3,12], [8], [11], [9]
 *    [3, 8, 12], [9, 11]
 *     [3, 8, 9, 11, 12]
*/

void mergeSort(int array[], int start, int end);
void merge(int array[], int start_left, int end_left, int start_right, int end_right)
void printArray(int array[], int len);

int main(void)
{
    int unsortedArray[] = {63, 21, 3, 25, 10, 98, 23, 47, 38};
    int len = sizeof(unsortedArray)/sizeof(unsortedArray[0]);

    printArray(unsortedArray, len);

    mergeSort(unsortedArray, 0, len - 1);

    printArray(unsortedArray, len);
}

void mergeSort(int array[], int start, int end)
{
    if (end > start)
    {
        int middle = (start + end) / 2;

        // Divide the array to two sub arrays(left, right)
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);

        merge(array, start, middle, middle + 1, end);
    }
}

// Merge two subarrays of the original array
// First subarray is array[start_left ... end_left]
// Second subarray is array[start_right ... end_right]
void merge(int array[], int start_left, int end_left, int start_right, int end_right)
{
    // Length of temp array
    int len = end_right - start_left + 1;

    // Create temp array
    int temp[len];

    int counter_left = start_left, counter_right = start_right, counter_temp = 0;

    // Copy data to temp array by merging two sub arrays(left, right)
    // when merge, compare the element of left array with right array
    while (counter_left <= end_left && counter_right <= end_right)
    {
        if (array[counter_left] < array[counter_right])
        {
            temp[counter_temp] = array[counter_left];
            counter_left++;
        }
        else
        {
            temp[counter_temp] = array[counter_right];
            counter_right++;
        }

        counter_temp++;
    }

    // Copy the reaming element of left array, if there are any
    while (counter_left <= end_left)
    {
        temp[counter_temp] = array[counter_left];
        counter_left++;

        counter_temp++;
    }

    // Copy the reaming element of right of array, if there are any
    while (counter_right <= end_right)
    {
        temp[counter_temp] = array[counter_right];
        counter_right++;

        counter_temp++;
    }

    // Copy the elements in temp array to the array that we want to sort
    for (int i = start_left, j = 0; j < len; i++, j++)
    {
        array[i] = temp[j];
    }
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