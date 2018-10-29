#include <stdio.h>

void insertionSort(int array[], int len);
void printArray(int array[], int len);

int main(void)
{
    int unsortedArray[] = {63, 21, 3, 25, 10, 98, 23, 47, 38};
    int len = sizeof(unsortedArray)/sizeof(unsortedArray[0]);

    printArray(unsortedArray, len);

    insertionSort(unsortedArray, len);

    printArray(unsortedArray, len);
}

void insertionSort(int array[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int unsorted_value = array[i];
        int insertion_position = i - 1;
        
        while (insertion_position >= 0 && array[insertion_position] > unsorted_value)
        {
            array[insertion_position + 1] = array[insertion_position];
            insertion_position--;
        }       
        array[insertion_position] = unsorted_value;       
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
