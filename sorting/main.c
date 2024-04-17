/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Include header files
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
#include <stdio.h>
#include <stdlib.h>

// Sorting
#include "merge.h"
#include "heap.h"
#include "bubble.h"
#include "quick.h"

// Search
#include "search_sorted_arr.h"


/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Util functions declarations
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
void printArray(int*, int);



/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Main function
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
int main() {
    int arr[] = {12, 11, 10, 9, 100, 399, 398, 397, 396, 395};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, arr_size);

    #ifdef QUICK
        printf("Sort the array with quick sort\n");
        quickSort(arr, 0, arr_size - 1);
    #endif

    #ifdef BUBBLE
        printf("Sort the array with bubble sort\n");
        bubbleSort(arr, arr_size);
    #endif

    #ifdef HEAP
        printf("Sort the array with heap sort\n");
        heapSort(arr, arr_size - 1);
    #endif

    #ifdef MERGE_R
        printf("Sort the array with recursive merge sort\n");
        mergeSortRecursive(arr, 0, arr_size - 1);
    #endif

    #ifdef MERGE_I
        printf("Sort the array with iterative merge sort\n");
        mergeSortIterative(arr, arr_size - 1);
    #endif


    printArray(arr, arr_size);

    bool result = false;
    int target = 12;

    #ifdef SEARCH_LOOP
    while(target != 0)
    {
    scanf("%d", &target);
    #endif
    result = binarySearch(arr, 0, arr_size - 1, target);
    printf("Search %d in array is %c\n", target, result? 'V':'X');

    result = linearSearch(arr, arr_size, target);
    printf("Search %d in array is %c\n", target, result? 'V':'X');

    #ifdef SEARCH_LOOP
    }
    #endif

    return 0;
}

/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Util functions definitions
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 */
void printArray(int *arr, int size) 
{
    if(!arr) return;

    for(int i = 0; i < size; i++)
    {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

