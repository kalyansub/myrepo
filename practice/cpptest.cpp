#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cpptest.h"

using namespace std;

MyTest::MyTest(int numArray[], char Words[])
{
    for(int i = 0; i < MAX; i++)
    {
        this->m_Numbers[i] = numArray[i];
        this->m_Words [i]= Words[i];
    }
}

MyTest::~MyTest()
{
    cout << "Destructor for MyTest invoked...\n";
}

void MyTest::printNum(void)
{
    for(int i = 0; i < MAX; i++)
    {
        cout << this->m_Numbers[i] << " ";
    }
}
void MyTest::printWords(void)
{
    for(int i = 0; i < MAX; i++)
    {
        cout << this->m_Words[i] << " ";
    }
}

int main(int argc, char* argv[])
{
    int arr[]= {1,2,3,4,5,6,7,8,9,0};
    char words[MAX];
    char tmp[2];
    for(int i = 0; i < MAX; i++)
    {
        words[i] = 'i' - '0'; 
    }
    MyTest mt(arr, words);
    cout << "Numbers in mt: ";
    mt.printNum();
    cout << "Words in mt: ";
    mt.printWords(); 
    cout << "All Done!\n";
    return 0;
}

