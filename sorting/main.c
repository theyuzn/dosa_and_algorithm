#include <stdio.h>
#include <stdlib.h>

#include "merge.h"
#include "heap.h"
#include "bubble.h"
#include "quick.h"


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

    printf("------------>\n");

    #ifdef QUICK

    #endif

    #ifdef BUBBLE
    
    #endif

    #ifdef HEAP
        heapSort(arr, arr_size - 1);
    #endif

    #ifdef MERGE_R
        mergeSortRecursive(arr, 0, arr_size - 1);
    #endif

    #ifdef MERGE_I
        mergeSortIterative(arr, arr_size - 1);
    #endif


    printArray(arr, arr_size);
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

