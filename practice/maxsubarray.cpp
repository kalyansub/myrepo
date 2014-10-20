/* Given an array of some length, find the contiguous sub-array with the maximum sum;
 * the standard technique to solve this is a DP divide and conquer method;
 * divide the array into two halves, 1 to mid, (mid+1) to end.
 * Return the maximum of the following three:
 * a) Max subarray sum in left half (make a recusrive call)
 * b) Max subarray sum in right half (make a reccursive call)
 * c) Max subarray sum such that the subarray crosses midpoint
 *
 * The functions a and b are simple recursive calls; for c,
 * find the max starting from mid and ending on some point left of mid
 * then, find max sum starting mid+1 and ending on some point right of mid+1
 * finally, combine the two above and return.
 * Order of this algorithm is O(n*log(n))
 */

#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
 return a>b?a:b;
}

int max(int a, int b, int c)
{
    return max(max(a,b),c);
}

int maxCrossingSum(int arr[], int low, int mid, int hi)
{
    // Add all elements to the left of mid value 'mid'
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    // Add all elements to the right of mid value 'mid'
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid+1; i<= hi; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    // Return sum on left and right
    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int low, int hi)
{
    //Base case: only 1 element
    if (low == hi)
        return arr[low];

    // Find mid point
    int mid = (low + hi ) >>1;

   // Return the max of the following three sums:
   // a) max subarray sum in the left half from mid
   // b) max subarray sum in the right half from mid
   // c) max subarray such that the subarray crosses midpoint

   return max(maxSubArraySum(arr, low, mid),\
              maxSubArraySum(arr, mid+1, hi),\
              maxCrossingSum(arr, low, mid, hi)
             );
}

/*Driver program to test maxSubArraySum*/
int main()
{
   //int arr[] = {-2, -3, 4, -1};
   int arr[] = {13, 14, -6, -2, -3, -1, -5, -6};    
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = maxSubArraySum(arr, 0, n-1);

   printf("Maximum contiguous sum is %d\n", max_sum);

   return 0;
}
