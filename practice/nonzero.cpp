/* Facebook interview quesiton:
Write an algorithm that brings all nonzero elements to the left of the array, and returns the number of nonzero elements. 

Example input: [ 1, 0, 2, 0, 0, 3, 4 ] 
Example output: 4 

[1, 4, 2, 3, 0, 0, 0] 

* The algorithm should operate in place, i.e. shouldn't create a new array. 
* The order of nonzero elements does not matter 
*/

#include <iostream>
#include <string>

using namespace std;

int shuffle(int& arr);

int shuffle(int* arr, int size)
{
    int nonZeroCount = 0; 
    int k = 0;

    if(arr != NULL)
    {
        for(int i = 0, j = 0; i < size; i++)
        {
            if(arr[i] != 0)
            {
                nonZeroCount++;
                arr[j] = arr[i];
                j++;
            }
        } 

        for (k = nonZeroCount; k < size ; k++)
        {
            //cout << "Inserting 0 at index k = " << k << "\n";
            arr[k] = 0;
        }
        return nonZeroCount;
    }
    else
    {
        cout << "Input arr NULL pointer!\n";
        return -1;
    }
}

int main(int argc, char* argv[])
{
    int testArray[] = {1, 2, 0, 0, 3, 0, 0, 0, 0, 4, 0, 5, 0, 0, 6, 7, 0};
    int size = sizeof(testArray)/sizeof(testArray[0]);
    int numNonZero = 0;

    cout << "Original array elements:" << "\n";
    cout << "[";
    for(int i = 0; i < size - 1; i++)
    {
        cout << testArray[i] << ",";
    }
    cout << testArray[size-1] << "]" << "\n";
    
    numNonZero = shuffle(testArray, size);
    cout << "nonZeroCount = " << numNonZero << "\n";

    cout << "Shuffled array elements:" << "\n";
    cout << "[";
    for(int i = 0; i < size-1; i++)
    {
        cout << testArray[i] << ",";
    }
    cout << testArray[size-1] << "]" << "\n";
    
    return 0;
}
