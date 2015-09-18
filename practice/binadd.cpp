/* FB Interview question: given two input strings s1, s2 each one is a binary representation of a number, add the two and print the answer as a binary string */

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int binStringToNum(string s);
string numToBinString(int num);


int binStringToNum(string s)
{
    unsigned char c;
    int len = s.length(), num = 0;
#ifdef __DEBUG
    cout << "len of string input: " << s << " is : "<< len << "\n";
#endif 
    for(int i = 0, j = len -1; i < len && j > 0; i++, j--)
    {
        c = s.at(i);
#ifdef __DEBUG
       cout << "at i= " << i << "character read: " << c << "\n"; 
#endif 
        c == '1'? num |= (1 << j): num;
#ifdef __DEBUG
        cout << "at i= " << i << "number formed so far: " << num << "\n"; 
#endif 
    }
#ifdef __DEBUG
    cout << "returning num = " << num << "\n";
#endif 
    return num;
}

string numToBinString(int num)
{
    int i = 0;
    int len = (int)log2(num)+1;
    string str;
    cout << "Got intput :" << num << " with length in bits calculated as : " << len << "\n";

    for ( i = 0; i < len && num > 0; i++ )
    {
        cout << "num %2 = " << num%2 << "\n";
        char ch = (num%2)?'1':'0';    
        cout << "ch = " << ch << "\n";
        str.push_back(ch);
        cout << "str[" << i << "] = " << str[i] << "\n";
        num = num/2;
        cout << "num/2 = " << num << "\n";
    }
   cout << "Returning string: str[] = " << str << "\n";

   return str;
}

int main(int argc, char* argv[])
{
    string s1 = "1010", s2="1100", s3 = " ";
    int n1 = 0, n2 = 0;  

    n1 = binStringToNum(s1);
    n2 = binStringToNum(s2);
    cout << "n1 = " << n1 << " n2 = " << n2 << " sum : " << (n1+n2)  << "\n";

    s3 = numToBinString(n1+n2);

    cout << "Sum of s1: " << s1 << " and " << " s2: " << s2 << " is : ";

    for(string::reverse_iterator rit = s3.rbegin(); rit != s3.rend(); ++rit)
    {
        cout << *rit;
    }
    cout << "\n";


    return 0;
}
