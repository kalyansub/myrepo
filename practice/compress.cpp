/* CtCI Intreview problem: Implement basic string compression using an algorithm to replace repeated occurrences of a character with its count after the character, e.g., aabbbcccc becomes a2b3c4. If the compressed string would be longer than the original, return the original string. */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int charCount[256]; // Assume ASCII set of characters, this is the count of ocurrance of each

string compress(string input);
string insertCharAt(string inStr, char ch, int position, string compStr);


string insertCharAt(string inStr, char ch, int position, string compStr)
{
    string first = inStr.substr(0, position);
    string last = inStr.substr(position);
    cout << "In insertCharAt(): first = [" << first << "]," <<  "ch = " << ch << ", last = [" << last << "]," << "position = " << position << endl;

    compStr = (first + first.insert(position, 1, ch)  + last);
    cout << "Returning: [" << compStr << "]" << endl;
    return compStr;
}

string compress(string inputStr)
{
    int origLen = inputStr.length();
    char c;
    string compStr;

    for(int i = 0; i < origLen; i++)
    {
        c = inputStr.at(i);
        cout << "i = " << i << "c = " << c << "\n";
        ++charCount[(int)c]; 
        cout << "charCount[" << c << "] = " << charCount[(int)c] << "\n";
    }
    for(int j = 0; j < origLen; j++)
    {
        c = inputStr.at(j);
        cout << "compress(): calling insert with charCount[" << (int)c << "]" << charCount[(int)c] << "\n";
        compStr = insertCharAt(inputStr, (char)charCount[(int)c], j+charCount[(int)c]-1, compStr);
    }

   return inputStr;
}

int main(int argc, char* argv[])
{
    string* myStr = new string("aabbbcccc");
    string retStr = compress(*myStr);
    cout << "Returned retStr: [" << retStr << "]\n";

    delete myStr;
    return 0;
}
