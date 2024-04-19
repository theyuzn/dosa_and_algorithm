#if defined(MERGE_R) || defined(MERGE_I)
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void merge(int* arr, int left, int middle, int right)
{
    int i = 0, j = 0, k = left;

    int size_l  = middle - left + 1;
    int size_r  = right - middle;

    int *arr_l  = (int*) calloc(size_l, sizeof(int));
    int *arr_r  = (int*) calloc(size_r, sizeof(int));

    memcpy(arr_l, arr + left, sizeof(int) * size_l);
    memcpy(arr_r, arr + middle + 1, sizeof(int) * size_r);
    
    while(i < size_l && j < size_r) 
    {
        if(arr_l[i] <= arr_r[j]) 
            arr[k++] = arr_l[i++];
        else 
            arr[k++] = arr_r[j++];
    }

    // Copy the remaining elements of L[], if any
    if(i < size_l)
    {
        memcpy(arr + k, arr_l + i, (size_l - i) * sizeof(int));
    }

    if(j < size_r)
    {
        memcpy(arr + k, arr_r + j, (size_r - j) * sizeof(int));
    }
    // while(i < size_l) 
    // {
    //     arr[k++] = arr_l[i++];
    // }

    // // Copy the remaining elements of R[], if any
    // while (j < size_r) 
    // {
    //     arr[k++] = arr_r[j++];
    // }
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

#endif