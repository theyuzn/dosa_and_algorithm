#ifdef INSERTION

#include "insertion.h"
#include "swap.h"


// Function to perform insertion sort
void insertionSort(int *arr, int size) 
{
    int i, key, j;
    for(i = 1; i < size; i++) 
    {
        key     = arr[i];
        j       = i - 1;


        while(j >= 0 && arr[j] > key) 
        {
            swap(&arr[j + 1], &arr[j]);
            j = j - 1;
        }
    }
}

#endif