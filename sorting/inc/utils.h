#ifndef __UTILS_H__
#define __UTILS_H__

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#endif // __UTILS_H__