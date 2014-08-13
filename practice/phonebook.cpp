// Phone book search using hash table implemented using STL map
// associative array of name and number, searchable by name and number...

#include <iostream>
#include <map>
#include <cstring>
#include "phonebook.h"

using namespace std;


// Define a "less than" operator for comparison: used for hashing
bool operator<(Name a, Name b)
{
    return strcmp(a.getName(), b.getName())< 0;
}

int main(int argc, char* argv[])
{
    map<Name, PhoneNumber> dir; // Directory has NULL entries for all at this point

    Name name1("Joe");
    PhoneNumber number1("310-55-1234");
    dir.insert(pair<Name,PhoneNumber>(name1, number1)); 

    dir.insert(pair<Name, PhoneNumber>(Name("Bob"), PhoneNumber("408-555-1234"))); 
    dir.insert(pair<Name, PhoneNumber>(Name("Bill"),PhoneNumber("550-555-1234"))); 

    // Given a name, find the number:
    char str[MAX];
    map<Name, PhoneNumber>::iterator i;
    
    do
    {
        cout << "Enter name to search for number: ";
        cin >> str;
        i = dir.find(Name(str));
        if (i!= dir.end())
            cout << "Phone number: " << i->second.getPhoneNumber() << "\n"; 
        else
            cout << "Phone number not found for: " << str << "\n";
    }
    while ( strcmp(str, "q") != 0);

    return 0;
}
