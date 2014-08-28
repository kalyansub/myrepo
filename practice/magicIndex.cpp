/* CtCI Intreview problem: A magin index is defined as an index of an array 'a', such that a[i] = i for a given value of i. Given that the values of the array are sorted and unique, write a fucntion to find the magic index. Second case: values are not unique, but still sorted: modify the function to take care of this case */

// e.g. a[11] = {-40, -20, -1, 1, 2, 3, 5, 7, 8, 12, 13};

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cassert>

using namespace std;

int binarySearch(int array[], int low, int high, int key);
vector<int> bruteForceFindUniqueMagicIndex(vector<int> a);
vector<int> findUniqueMagicIndex(vector<int> a);
//vector<int> findRepeatedMagicIndex(vector<int> a);

// Brute force search: O(n)
vector<int> bruteForceFindUniqueMagicIndex(vector<int> a)
{
   vector<int> found;
   int index = 0;

   for(vector<int>::iterator i = a.begin(); i != a.end(); ++i, index++)
   {
       if (*i == index) 
       {
          cout << "Found value = " << *i << " at magic index :[" << index << "]\n";
          found.push_back(index);
       }
       else
       {
          cout << "Not Found value = " << *i << " at index : " << index << "\n";
          found.push_back(-1); //Not found is indicated by -1
       }
   } 
   return found;
}

///////////////////////////////////////////////////////
int binarySearch(int array[], int low, int high, int key)
{
    int index = 0;
    
    if(low > high)
        return -1;

    int mid = (low + high)>>1;

    if(array[mid] == key)
    {
       index = mid; 
    }
    else 
    {
       if(array[mid] < key) // means that the sought for value is to the right, so mid+1 to high 
       {
           index = binarySearch(array, mid+1, high, key);  
       }
       else if(array[mid] > key)// means that the sought for value could lie on either side
           index = binarySearch(array, low, mid-1, key); 
    } 
    //cout << "binarySearch(): index= " << index << "mid = " << mid << " key = " << key << "\n";
    return (index == key) ? index: -1;
}


///////////////////////////////////////////////////////
vector<int> findUniqueMagicIndex(vector<int> a)
// Same algorithm, sped up by Binary search: O(log n)
{
    vector<int> found;
    int index = 0, first, last;
    int mid;

    cout << "in function: findUniqueMagicIndex()\n"; 
    vector<int>::iterator i = a.begin();
    first = *max_element(a.begin(), a.end());
    cout << "first = " << first << "\n";
    last = accumulate(a.begin(), a.end(), 0);
    cout << "last = " << last << "\n";
    mid = (first + last)/2;
    cout << "mid = " << mid << "\n";
    index = mid;
    cout << "*i = " << *i << "\n";
    cout << "a.at(mid) = " << a.at(mid) << "\n";

    assert(*i != 0);

    if (*i == a.at(mid)) 
    {
        cout << "Found value = " << *i << "at magic index : [" << mid << "]\n";
        found.push_back(a.at(mid));
    } 
// Middle entry doesn't look like a magic one, if it is less than the index, that means all elements to the left of mid MUST be smaller than the mid and also, magic ones lie to the right since the array is sorted and unique!!
    else if ( a.at(mid) < *i)
    {
       cout << "Entered right half of the vector search with mid: " << mid <<"\n";
       for( *i = a.at(mid+1), index = mid+1; i != a.end(); ++i, index++)
       {
          if(*i == index) 
          {
              cout << "Found value = " << *i << "at magic index : [" << index << "]\n";
              found.push_back(index);
          }
          else
          {
              cout << "Not Found value = " << *i << " at index : " << index << "\n";
              found.push_back(-1); //Not found is indicated by -1
          }
          mid = (mid + *a.end())/2;
       } 
    }
// The only other possible case is the entry is greater than the index,it means the magic index could lie on either side of the mid value; recursively subdivide each half and binary search each half... 
   else if ( a.at(mid) > *i)
   {
   }
}

int main(int argc, char* argv[])
{
    vector<int> a; // case of unique sorted values in vector
    vector<int> foundIndex; // return values of indices found in this vector
    int index = 0;

    a.push_back(-40);
    a.push_back(-20);
    a.push_back(-1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(8);
    a.push_back(12);
    a.push_back(13);

    cout << "done filling in vector values!\n";

/*
    foundIndex  = bruteForceFindUniqueMagicIndex(a);
    cout << "Brute force Unique case: foundIndex array is : " << "\n";
    for(vector<int>::iterator it = foundIndex.begin(); it != foundIndex.end(); ++it)
    {
         if (*it != -1)
         {
             cout << "Magic index found at index:[" << *it  << "]\n";
         }
    }
*/
    int i = 0;
    int arr[11];

    for(vector<int>::iterator it = a.begin(); it != a.end(); ++it, i++)
    {
        arr[i] = a.at(i); 
        cout << "Converting arr[" << i << "] = " << arr[i] << "\n";
        index = binarySearch(&arr[0], 0, a.size(), i);
        //cout << "binarySearch returned value: " << index << "\n";
        if(index != i)
        {
            cout << "## Couldn't find  a magic index: " << index << "at i = " << i << "\n"; 
            foundIndex.push_back(index);
        }
        else
        {
            cout << "** YES!! found a magic index: " << index << "at i = " << i << "\n"; 
            foundIndex.push_back(index);
        }
    }
    /*
    foundIndex = findRpeatedMagicIndex(&a, index);
    cout << "Non uninque case: found index: " << myIndex2 << "\n";
    */

    return 0;
}

