/* Facebook interview problem:
  Given an array of integers. We have to find the max element of the array, which is at multiple places in the array and return any one of the indices randomly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomSelect(int a, int b)
{
    if (rand()%2 || a < 0)
    {
        printf("returning :%d\n", b);
        return b;
    }
    else
    {
        printf("returning :%d\n", a);
        return a;
    }
}   

int findMax(int a[], int size)
{
    int max = 0;
    int maxIndex = -1;
    int i = 0;
    time_t t;
    int* maxIndexArr;
    int maxCount = 0;

    maxIndexArr = (int* )calloc(size, sizeof(int));
    if(maxIndexArr == NULL)
    {
        printf("calloc() failed on maxINdexArr!\n");
        return -1;
    }
    srand((unsigned) time(&t));
    for(i = 0; i < size; i++)
    {
        if( max < a[i])
        {
            max = a[i];
            maxIndex = i;
            maxIndexArr[maxCount++] = maxIndex;
        }
        else if(max == a[i])
        {
           /*maxIndex = randomSelect(maxIndex, i);*/ 
           maxIndexArr[maxCount++] = i;
        }
    }
    printf("maxCount = %d\n", maxCount);
    int x = maxCount*((float)rand())/RAND_MAX; 
    printf("Generated random value: %d\n", x);
    printf("maxIndexArr[%d] = %d\n", x, maxIndexArr[x]);
    /*
    for ( i = 0; i < maxCount; i++)
    {
        printf("maxIndexArr[%d] = %d\n", i, maxIndexArr[i]);
        if ( x % 2  )
        {
            printf("choosing ith value: %d\n", maxIndexArr[i]);
            maxIndex = maxIndexArr[i];
        }
        else
        {
            printf("choosing i+1 th value: %d\n", maxIndexArr[i+1]);
            maxIndex = maxIndexArr[i+1];
        }
    }
    */
    free(maxIndexArr);
    return maxIndex;
}
int main(int argc, char* argv[])
{
    int a[21] = {1,4,9,7,3,9,4,7,2,7,3,0,1,2,9,6,5,7,8,9}; 
    int i;

    printf("Found max at index : %d\n", findMax(a, 21));

    return 0;
}
