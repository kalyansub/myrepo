/* Write a C++ program to convert a given number in the range [0 ...255] to hexadecimal 
 *
 * $Author$: Kalyan Subramanian
 * $Date$:  October 23, 2014
 * $Email$: kalyan dot sub at gmail dot com
 *
 * */

#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::reverse;

void convertDigitToString(int digit, string& output)
{
    char tableNum[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char tableChar[] = { 'A', 'B', 'C', 'D', 'E', 'F'};

    if (digit < 10)
    {
        output.push_back(tableNum[digit]);
    }
    else
    {
        digit -= 10;
        output.push_back(tableChar[digit]);
    }
}


int main(int argc, char* argv[])
{
    int input;
    string output;

    cout << "Enter input number to convert to hex: \n";
    cin >> input; 

    int q, r;
    q = input >> 4; // divide by 16
    r = input & 0xF; // modulo 16, (implemented as & 2^n -1, i.e., & 0xF)

    convertDigitToString(q, output);
    convertDigitToString(r, output);

    reverse(output.begin(), output.end());

    cout << "Output string in hex is :0x" << output << endl;

    return 0;
}
