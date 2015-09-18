/*  
 * Stack implementation using a vector of strings. Note how
 * the Pop() member function uses a vector pop_back().   
 *     
 * $Author$: Kalyan Subramanian
 * $email$: kalyan dot sub at gmail
 * $Date$: Oct 2, 2014 
*/
#include <iostream>
#include <cassert>
#include "stack.h"

using std::cout;
using std::endl;

enum {MAX_ELEMENTS = 10};

Stack::Stack()
:m_Elements(vector<string>(MAX_ELEMENTS)),
m_Capacity(m_Elements.capacity()), 
m_StackPtr(0)
{
    assert (&m_Elements != NULL);
}

Stack::~Stack()
{
}

void Stack::Push(const string& inputStr)
{
    m_Elements.push_back(inputStr);
    if(m_Capacity > 0)
        m_Capacity--;
    ++m_StackPtr;
}

void Stack::Pop(string& retStr)
{
    retStr = m_Elements.back();
    m_Elements.pop_back();
    m_StackPtr--;
    cout << "Pop(): current pointer to top of Stack is : " << m_StackPtr << endl;
}

void Stack::Print(void)
{
    for( vector<string>::const_iterator i = m_Elements.begin(); i != m_Elements.end(); ++i )
    {
        cout << (*i) << endl;
    } 
}

int main(int argc, char* argv[])
{
    Stack myStack;

    myStack.Push("one");
    myStack.Push("two");
    myStack.Push("three");
    myStack.Push("four");

    myStack.Print();

    if ( !myStack.isEmpty() )
    {
         string retStr;
         myStack.Pop(retStr);
         cout << "Pop() returned : " << retStr << "\n";
    }
    return 0;
}
