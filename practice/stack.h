/*
 * Stack implementation using a vector of strings. Note how
 * the Pop() member function uses a vector pop_back().
 *
 * $Author$: Kalyan Subramanian
 * $email$: kalyan dot sub at gmail
 * $Date$: Oct 2, 2014
 *
 */
#ifndef __STACK_H_INCLUDED__
#define __STACK_H_INCLUDED__
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Stack
{
    public:
        Stack();
        ~Stack();
        inline bool isEmpty(void) { cout << "isEmpty(): m_Capacity = " << m_Capacity << endl; return (m_Capacity == 0); }
        void Push(const string& addStr);
        void Pop(string& retStr); 
        void Print(void);

    private:
        // Dsiallow copy c'tor and assigment operator:
        Stack(Stack& copyFrom);
        Stack& operator=(const Stack& rhs);

        vector<string> m_Elements;
        int            m_StackPtr;
        int            m_Capacity;
};

#endif //__STACK_H_INCLUDED__
