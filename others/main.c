#include <stdio.h>


static char *test[7] = {
#include "test.inc"
};

void printArr(char **arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%s  \n", arr[i]);
}

int main(void)
{
    printArr(test, 7);
    return 0;
}

