/* CtCI question: reverse the max and min numbers in an  array of integers */

#include <stdio.h>

void reverseMinMax(int* arr, int size);

void reverseMinMax(int* arr, int size)
{
    int minIndex = 0, maxIndex = 0;

    int i, temp = 0;

    for(i = 0; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    for(i = 0; i < size; i++)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;
}

int main(int argc, char* argv[])
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int i;
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("original array:[");
    for (i = 0; i < size -1; i++)
    {
        printf(" %d, ", arr[i]);
    }
    printf(" %d]\n", arr[size-1]);

    reverseMinMax(arr, size);

    printf("reversed min max array:[");
    for (i = 0; i < size -1; i++)
    {
        printf(" %d, ", arr[i]);
    }
    printf(" %d]\n", arr[size-1]);

    return 0;

}
