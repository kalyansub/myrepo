/* Interview problem: given an array of 'n' integers, some of which repeat some numberof times, find out the ones that are repeats. e.g. For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6}, the answer should be 1, 3 and 6.

The algorithm here is as follows:
traverse the list for i= 0 to n-1 elements
{
  check for sign of A[abs(A[i])] ;
  if positive then
     make it negative by   A[abs(A[i])]=-A[abs(A[i])];
  else   i.e., A[abs(A[i])] is negative
     this   element (ith element of list) is a repetition
}
This is O(n) time and O(1) in space, i.e. uses the same input array. Caveats: doesn't handle caseof 0s in the input.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int finddups(int* arr, int size)
{
    int i, count = 0;

    for (i = 0; i < size; i++)
    {
        if( (arr[abs(arr[i])] >= 0) )
        {
             arr[abs(arr[i])]  = -arr[abs(arr[i])]; 
        }
        else
        {
              count++;
              printf("Item %d: is repeated!\n", abs(arr[i]));
        }
    }
}

int main(int argc, char* argv[])
{
     int arr[] =  {0, 1, 2, 3, 1, 3, 6, 6, 7, 8, 8, 9, 9, 9, 10, 10, 11, 11, 11, 23, 12, 1, 23};
     int size = sizeof(arr)/sizeof(arr[0]);
     int repcount = 0;

      repcount = finddups(arr, size);
      printf("Found %d repeated items in array\n", repcount);
 
     return 0;
}
