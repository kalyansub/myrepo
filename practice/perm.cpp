//CtCI problem 1.3: Write a function to find if a string s1 is a permutation of a string s2; whitespace counts as part of the strings, and the function is case sensitive, e.g. God is considered a valid permutaiton of 'dog'.

/* Algorithm used:
   Pre-condition: String 1 has to be smaller or equal than String 2.

1) Traverse the smallest string and make each character of that string a key in a hash map that holds the occurrence value of that particular character.

2) Do the same thing for the bigger (or equal size) string.

3) Compare if the occurrence of each character in String 1 is equal or smaller than the occurrence of each character in String 2.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <assert.h>
 
using namespace std;
 
/**
* Returns a hash map with the occurrence of each character in a string
* @param string s
* @return unordered_map< char, int >    Contains the key, value pair of the occurrence of each character in the input string
*/
unordered_map< char, int > countOccurrence(string s)
{
    unordered_map< char, int > map;
    for (int i = 0; i < s.size(); ++i)
    {
        char character = s.at(i);
        if (map.find(character) == map.end())
            map[character] = 1;
        else
            map[character]++;
    }
    return map;
}
 
/**
* Checks if s1 is a permutation of s2
* @param string s1
* @param string s2
* @return True if s1 is a permutation of s2, false otherwise
*/
bool isPermutation(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    unordered_map< char, int > occurrence1 = countOccurrence(s1);
    unordered_map< char, int > occurrence2 = countOccurrence(s2);
    for (int i = 0; i < s1.size(); ++i)
    {
        char character = s1.at(i);
        if (occurrence2.find(character) == occurrence2.end() || occurrence1.at(character) > occurrence2.at(character))
            return false;
    }
    return true;
}
 
int main()
{
    string s1 = "hello";
    string s2 = "hello world";
    string s3 = "abc world";

    string s4 = "dad had a big cat";
    string s5 = "had cat a big dad";

    assert(isPermutation(s1, s2) == true);
    assert(isPermutation(s3, s2) == false);
    assert(isPermutation(s2, s1) == false);

    assert(isPermutation(s4, s5) == true);

    return 0;
}

