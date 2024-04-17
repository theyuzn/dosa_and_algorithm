#include "search_sorted_arr.h"

bool binarySearch(int *arr, int low, int high, int target)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] < target)
            low = mid + 1;
        else if(arr[mid] > target)
            high = mid - 1;
        else
            return true;
    }

    return false;
}

bool linearSearch(int *arr, int size, int target)
{
    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] == target)
            return true;
    }
    return false;
}