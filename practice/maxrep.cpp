/* Given an array of size n, the array contains numbers in range from 0 to k-1,
 * where k is a positive integer and k <= n. Find the maximum repeating number
 * in this array. For example, let k be 10 the given array be: 
 * arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3}, the maximum repeating 
 * number would be 2. Expected time complexity is O(n) and extra space allowed 
 * is O(1). Modifications to the original array are allowed.  
 */
 
#include <iostream>
using std::cout;
using std::endl;

// Inputs: array of n integers, a positive number k such that 0 < k <= n
int findMaxRepeatedElement(int* arr, int n, int k)
{
    //Iterate through input array arr for each element, arr[i] and 
    //increment arr[arr[i]%k] by k    
    for(int i = 0; i < n; ++i)
    {
        arr[arr[i]%k] += k;
    }
    //
    // Find index of the maximum repeating element
    int max = arr[0], maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main()
{
    int arr[] = {1,2,2};
    //int arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
 
    cout << " n = " << n << endl;
    cout << "The maximum repeating number is " <<
         findMaxRepeatedElement(arr, n, k) << endl;
 
    return 0;
}
