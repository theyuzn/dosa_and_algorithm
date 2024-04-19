#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static inline void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Use Greedy // Find max sum of sub-array
// The element could be negative
static int MaximumSubarray(int *arr, int size)
{
    if(!arr) return 0;
    if(size == 1) return arr[0];
    if(size == 2) return arr[0] + arr[1];

    int *temp_max = (int*) calloc(size, sizeof(int));
    int max = 0;

    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            temp_max[i] = arr[i];
            max = arr[i];
            continue;
        }

        int temp = arr[i] + temp_max[i - 1];
        temp_max[i] = fmax(temp, arr[i]);
        max = fmax(max, temp_max[i]);
    }

    return max;
}


// Find Largest( subarray(min + max) )
// [1, 5, 3, 8, 9] --> subarray {8, 9} = 17;
// [1, 8, 5, 3, 9] --> subarray {8, 5, 3, 9} = 17;
// Sorted and find the first and second largest ???
static int Largest(int *arr, int size)
{
    if(!arr) return 0;
    if(size == 1) return arr[0];
    if(size == 2) return arr[0] + arr[1];

    int max_sum = 0;
    int min_val = arr[0];
    int max_val = arr[0];

    for(int i = 1; i < size; i++) 
    {
        max_sum = fmax(max_sum, max_val + arr[i]);
        max_sum = fmax(max_sum, min_val + arr[i]);

        max_val = fmax(max_val, arr[i]);
        min_val = fmin(min_val, arr[i]);
    }

    return max_sum;
}


static int pivot(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for(int j = low; j < high; j++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

static int theKthLargestNum(int *arr, int size, int k)
{
    if(!arr) return -1;
    if(size < k) return -1;

    int left = 0, right = size - 1;

    while(1)
    {
        int pivot_idx = pivot(arr, left, right);
        if(pivot_idx == k - 1) return arr[pivot_idx];
        else if(pivot_idx > k - 1) right = pivot_idx - 1;
        else left = pivot_idx + 1;
    }
}


int main()
{
    int arr_1[] = {10, -10, 2, -10, 8, 7, -3, 4, -1, -4, -5, 3, 9, 3, 4};
    int size_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    int largest_sum_of_subarr = MaximumSubarray(arr_1, size_1);
    printf("Largest{ subarray_sum }\t\t\t\t= %d\n", largest_sum_of_subarr);


    int arr_2[] = {1, 5, 10, 3, 8, 9};
    int size_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    int largest_min_add_max = Largest(arr_2, size_2);
    printf("Largest{ [ subarray_min ] + [ subarray_max ] }\t= %d\n", largest_min_add_max);


    int arr_3[] = {1, 5, 10, 3, 8, 9};
    int size_3 = sizeof(arr_3) / sizeof(arr_3[0]);
    int k = 3;
    int num = theKthLargestNum(arr_3, size_3, k);
    printf("%dth Largest\t\t\t\t\t= %d\n", k, num);
    return 0;
}