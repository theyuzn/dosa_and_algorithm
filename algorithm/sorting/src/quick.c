#if defined(QUICK) || defined(QUICK_API)

#include <stdlib.h>
#include <string.h>
#include "quick.h"
#include "swap.h"

static int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

static int str_compare(const void *a, const void *b)
{
    return strcmp(*(const char **) a, *(const char **) b);
}

void str_quickSort_api(char *str[], int size)
{
    qsort(str, size, sizeof(char*), str_compare);
}

void quickSort_api(int *arr, int size)
{
    qsort(arr, size, sizeof(int), compare);
}

static int pivot(int *arr, int low, int high) 
{
    int pivot_val = arr[high];  // Choose the last element as the pivot
    int i = low;                // Index of the smaller element

    for (int j = low; j < high; j++) 
    {
        if(arr[j] <= pivot_val) 
            swap(&arr[i++], &arr[j]);
    }
    swap(&arr[i], &arr[high]);

    // return the pivot index
    return i;     
}

// Recursive function to perform Quick Sort
void quickSort(int *arr, int low, int high) 
{
    if (low < high) 
    {
        int pivot_idx = pivot(arr, low, high);  // Partitioning index
        quickSort(arr, low, pivot_idx - 1);         // Sort the left subarray
        quickSort(arr, pivot_idx + 1, high);        // Sort the right subarray
    }
}

#endif