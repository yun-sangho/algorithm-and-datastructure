#include <stdio.h>

void binary_search(int array[], int len, int value);

int main(void)
{
    int array[] = {3, 10, 21, 23, 25, 38, 47, 63, 98};
    int len = sizeof(array)/sizeof(array[0]);
    
    binary_search(array, 0, len - 1, 10);
    binary_search(array, 0, len - 1, 49);
}

// Array has to be sorted before using binary search
int binary_search(int array[], int start, int end, int target)
{
    if (end >= start) 
   { 
        int middle = start + (end - start)/2; 
  
        // If the target element is present at the middle
        if (array[middle] == target)
        {
            printf("%i is %ith value in the array\n", value, middle + 1);
            return 1;
        }
            
        // If target element is smaller than middle, it only presents in left subarray from the middle.  
        if (array[middle] > target)
            return binarySearch(arr, start, middle - 1, target); 
  
        // Else the target element only presents in right subarray from the middle.
        return binarySearch(arr, middle + 1, end, target); 
   }
   
   // When the target element does not present in array
   printf("There is not %i in the array\n", value);
   return 0;
}
