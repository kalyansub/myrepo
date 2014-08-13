#include <iostream>
#include <cstring>

using namespace std;

void stringReverse(char* inputStr);

void stringReverse(char* inputStr)
{
    int len = strlen(inputStr);

    string outStr;

    char tmp = '\0';
    for( int i = 0; i < len >> 1 ; i++)
    { 
        tmp = inputStr[i] ;
        inputStr[i] = inputStr[len -i -1];
   } 
}
int main(void) 
{
    char str[100];
    cout << "you can input a string of characters or a sentence and I will reverse it for you" << endl;
    cin.getline(str, 99);
    cout << endl;
    cout << "your sentence or string in reverse is: " << endl;
    stringReverse(str); // string reversed function call
    cout << str << endl; // srting reprinted as is (forward)
    return 0;
}
