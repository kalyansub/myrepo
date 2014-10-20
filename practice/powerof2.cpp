/* Write a function to check if a given number is a power of 2 or not.
 * $Author$: Kalyan Subramanian
 * $Date$: Sep 5th, 2014
 * $email$: kalyan dot sub at gmail
 */

#include <iostream>
using std::cin;
using std::cout;

int main(int argc, char* argv[])
{
    int val;
    bool isPowerOf2 = false;

    cout << "Enter a number: ";
    cin >> val;

    if( val <= 0 )
    {
        cout << "The number " << val << " is not a power of 2!\n";
    } 
    else
    {
            isPowerOf2 = !(val & (val - 1)); //check if the LSB is NOT set
            if (isPowerOf2)
            {
                cout << "The number " << val << " is a power of 2\n";
            }
            else
            {
                cout << "The number " << val << "is a NOT power of 2\n";
            }
    }    
    return 0;
}
