#include <iostream>
using namespace std;

bool isKthBiSet(unsigned int x, unsigned int k);
bool isPalindrome(unsigned int x);

bool isKthBitSet(unsigned int x, unsigned int k)
{
    return (x & (1 << (k-1)))? true: false;
}

bool isPalindrome(unsigned int x)
{
    int left = 1;
    int right = sizeof(unsigned int)*8;

    //Compare bits one at a time:
    while (left < right)
    {
        if(isKthBitSet(x, left) != isKthBitSet(x, right))
            return false;
        left++;
        right--;
    }
    return true;
}

int main(int argc, char* argv[])
{
    unsigned int x = 1<<15 + 1<<16;
    cout << isPalindrome(x) << endl;
    x = 1L<<31 + 1;
    cout << isPalindrome(x) << endl;
    return 0;
}
