#include <stdio.h>
#include <cs50.h>

void swap(int array[], int i, int j);
void printArray(int len, int array[]);

int main(void)
{
    int len;

    do
    {
        len = get_int("Insert the length of array: ");

    } while (len < 0);

    int array[len];

    for (int i = 0; i < len; i ++)
    {
        int value = get_int("Insert the value of array: ");
        array[i] = value;
    }

    printArray(len, array);

    for (int i = 0; i < len - 1; i++)
    {
        int unsorted_value = array[i + 1];
        int insertion_position = i + 1;

        for (int j = i; j >= 0; j--)
        {
            if (array[j] > unsorted_value)
            {
                array[j + 1] = array[j];
                insertion_position--;
            } else
            {
                break;
            }
        }

        array[insertion_position] = unsorted_value;
    }

    printArray(len, array);
}

void swap(int array[], int i, int j)
{
    if (i == j)
    {
        return;
    }

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void printArray(int len, int array[])
{
    printf("Array: ");

    for (int x = 0; x < len; x ++)
    {
        printf("%i ", array[x]);
    }

    printf ("\n");
}
