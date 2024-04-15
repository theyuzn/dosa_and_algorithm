#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "merge.h"


void merge(int* arr, int left, int middle, int right)
{
    int i = 0, j = 0, k = left;
    int size_from_left_size     = middle - left + 1;
    int size_from_right_size    = right - middle;

    // Create temporary arrays
    int *left_arr  = (int*) calloc(size_from_left_size, sizeof(int));
    int *right_arr = (int*) calloc(size_from_right_size, sizeof(int));

    // Copy data to temporary arrays
    memcpy(left_arr, arr + left, sizeof(int) * size_from_left_size);
    memcpy(right_arr, arr + middle + 1, sizeof(int) * size_from_right_size);
    
    // Merge the temporary arrays back into arr[l..r]
    while(i < size_from_left_size && j < size_from_right_size) 
    {
        if(left_arr[i] <= right_arr[j]) 
        {
            arr[k++] = left_arr[i++];
        }
        else 
        {
            arr[k++] = right_arr[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while(i < size_from_left_size) 
    {
        arr[k++] = left_arr[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < size_from_right_size) 
    {
        arr[k++] = right_arr[j++];
    }
}



void mergeSortRecursive(int* arr, int left, int right)
{
    if(left < right)
    {
        // = (left + right) / 2, but this could avoid int overflow
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortRecursive(arr, left, middle);
        mergeSortRecursive(arr, middle + 1, right);

        merge(arr, left, middle, right);
        return;
    }
}


void mergeSortIterative(int *arr, int n) {
    int curr_size;
    int left_start;

    // Merge subarrays in bottom-up manner.
    // First merge subarrays of size 1 to create sorted subarrays of size 2,
    // then merge subarrays of size 2 to create sorted subarrays of size 4, and so on.
    for(curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) 
    {  
        for(left_start = 0; left_start < n - 1; left_start += 2 * curr_size) 
        {
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;

            if(right_end >= n)
            {
                right_end = n - 1;
            }

            merge(arr, left_start, mid, right_end);
        }
    }
}