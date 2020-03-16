// Check if two given strings are anagrams of each other
// This solution leverages the powerful comparison operator for unordered maps!
// $Author$: Kalyan Subramanian
// $Date$: Nov 2, 2014
// $email$: kalyan dot sub at gmail dot com
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) 
{
        if (s.size() != t.size())
            return false;
        
        unordered_map<char, int> table;
        for (char& ch : s)
            table[ch]++;
        for (char& ch : t)
            table[ch]--;
        for (auto it = table.begin(); it != table.end(); it++)
            if ((*it).second != 0)
                return false;
        return true;
}

/* This doesn't work!
bool isAnagram(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }

    int counter = 0; 
    unordered_map<char, int> htableA;
    unordered_map<char, int> htableB;
    createHashMap(a, freqCharA, htableA);
    createHashMap(b, freqCharB, htableB);
    // Use the powerful comparison operator for unordered_maps, i.e. "==" !
   return (htableA == htableB)? true: false;
}
*/
int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <string 1> <string2> \n";
        return -1;
    }
    
    string a(argv[1]);
    string b(argv[2]);

    if (isAnagram(a, b))
    {
        cout << a << " is an anagram of " << b << endl;
    }
    else
    {
        cout << a << " is NOT an anagram of " << b << endl;
    }
    return 0;
}
