#ifdef QUICK

#include "quick.h"
#include "swap.h"


int partition(int *arr, int low, int high) 
{
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) 
    {
        if(arr[j] <= pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Recursive function to perform Quick Sort
void quickSort(int *arr, int low, int high) 
{
    if (low < high) 
    {
        int pivot = partition(arr, low, high);  // Partitioning index
        quickSort(arr, low, pivot - 1);         // Sort the left subarray
        quickSort(arr, pivot + 1, high);        // Sort the right subarray
    }
}

#endif