#ifdef SELECTION

#include "insertion.h"
#include "swap.h"


void selectionSort(int *arr, int size) 
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for(i = 0; i < size - 1; i++) 
    {
        min_idx = i; // Find the minimum element in unsorted array
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
            min_idx = j;
            }         
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

#endif