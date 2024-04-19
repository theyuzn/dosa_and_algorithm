#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char *test[7] = {
#include "test.inc"
};

void printArr(char **arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%s  \n", arr[i]);
}


void triangle(int layer)
{
    for (int i = 0; i < layer; i++) 
    {
        for (int j = 0; j < layer - i - 1; j++)
            printf(" ");
        
        for (int j = 0; j < 2 * i + 1; j++)
            printf("*");
        
        printf("\n");
    }
}

void listSubarrays(int *arr, int n) 
{
    for (int start = 0; start < n; start++) 
    {
        for (int end = start; end < n; end++) 
        {
            printf("[");
            for (int i = start; i <= end; i++) 
            {
                printf("%d", arr[i]);
                if (i != end) {
                    printf(", ");
                }
            }
            printf("]\n");
        }
    }
}

int main(void)
{
    // printArr(test, 7);

    triangle(20);

    int arr[] = {1,2,3,4,5,6,7,8,9};

    listSubarrays(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}

