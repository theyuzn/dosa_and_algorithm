#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "swap.h"

void heap_heapify(int *arr, int n, int i) 
{
    int largest = i;            // Initialize largest as root
    int left    = 2 * i + 1;    // Left child
    int right   = 2 * i + 2;    // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heap_heapify(arr, n, largest);
    }
}

void buildHeap(int *arr, int n) 
{
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) 
        heap_heapify(arr, n, i);   
}