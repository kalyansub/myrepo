/* Write a function to find the size of int and char on any machine without using sizeof()
 * Roku interview question
 *
 * $Author$: Kalyan Subramanian
 * $Date$: September 10, 2014
 * $email$: kalyan dot sub at gmail dot com
 *
 */

#include <iostream>
using std::cout;

int main(int argc, char* argv[])
{
     int i = 1;
     int bits_in_int = 0;

    while ( i != 0 )
    {
        i <<= 1;
        ++bits_in_int;
    }
    
     char uc = 1;
     int char_bits = 0;

    while ( uc != 0 )
    {
        uc <<= 1;
        ++char_bits;
    }

    cout << "Type  int has: " << bits_in_int << " bits, or " << (bits_in_int>>3) << " bytes on this arch.\n";
    cout << "Type  char has: " << char_bits << " bits, or " << (char_bits>>3) << " bytes on this arch.\n";

    return 0;
}

