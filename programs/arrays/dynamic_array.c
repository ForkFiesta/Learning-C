#include <stdio.h>



int main()
{
    const originalSize = 16;
    struct dynamicArray {
        int *arrayAddress;
        int capacity;
        int size;
    };

    int original_array[originalSize];

    struct dynamicArray dynamicArray1;

    dynamicArray1.arrayAddress = &original_array;
    dynamicArray1.capacity = originalSize;
    dynamicArray1.size = original_array[0]*originalSize;

    





}