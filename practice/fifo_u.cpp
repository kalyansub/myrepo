/*
 * FIFO implementation and test code: A simple array based character FIFO with push and pop methods. 
 * Using unique_ptr implementation from the C++11 std library..

    $Author$: Kalyan Subramanian
    $email$: kalyan dot sub at gmail
    $Date$: Sep 16, 2014 
*/
#include <iostream>
#include <cassert>
#include "fifo_u.h"

using std::cout;
using std::move;

Fifo::Fifo(unique_ptr<char[]> elem, int len):
      m_Elements(new char[MAX_NUM]),
      m_Size(len), m_CurPos(0)
{
    cout << "Constructor called with size = " << m_Size << " curPos = " << m_CurPos << "\n"; 

    assert(m_Elements != NULL);
    m_Elements.reset(elem.release());
}

Fifo::~Fifo()
{
    cout << "Destructor called...\n"; 

    //if (m_Elements != NULL)
    //    delete [] m_Elements;

    m_CurPos = 0;
    //m_Elements = 0;
}
     
void Fifo::push(char ch)
{
    //cout << "+push() got char = "<< ch << ": m_Size = " << m_Size << " m_CurPos = " << m_CurPos << "\n";
    if ( ! isFull() )
    {
        m_Elements[m_CurPos++] = ch;
    }
    //cout << "-push() got char = "<< ch << ": m_Size = " << m_Size << " m_CurPos = " << m_CurPos << "\n";
}


char Fifo::pop(void)
{
    //cout << "+pop(): m_Size = " << m_Size << " m_CurPos = " << m_CurPos << "\n";
    char ch = '\0';
    if ( ! isEmpty() )
    {
        //cout << "pop(): current position of FIFO read ptr = " << (m_Size - m_CurPos) << "\n";
        ch = m_Elements[(m_Size - m_CurPos)];
        --m_CurPos;
    }
    //cout << "-pop(): m_Size = " << m_Size << " m_CurPos = " << m_CurPos << "\n";
    return ch;
}

char Fifo::print(void)
{
   for(int i = 0; i <= m_Size; ++i)
   {
       cout << "FIFO contains: [" << m_Elements[i] << "] at posistion: " << i << "\n";
   }
}

int main(int argc, char* argv[])
{
    //char* elems = new char[MAX_NUM];
    unique_ptr<char[]> elems(new char[MAX_NUM]);
    char ch;
    int len =  5;
    cout << "Length of array is : " << len << "\n";

    Fifo myfifo(move(elems), len); 

    myfifo.push('a');
    myfifo.push('b');
    myfifo.push('c');
    myfifo.push('d');
    myfifo.push('e');

    cout << "Contents of FIFO after successive push() calls: \n";
    cout << myfifo.print();

    ch = myfifo.pop();
    cout << "Popped ch = [" << ch << "]\n"; 
    ch = myfifo.pop();
    cout << "Popped ch = [" << ch << "]\n"; 
    ch = myfifo.pop();
    cout << "Popped ch = [" << ch << "]\n"; 
    ch = myfifo.pop();
    cout << "Popped ch = [" << ch << "]\n"; 
    ch = myfifo.pop();
    cout << "Popped ch = [" << ch << "]\n"; 

    //delete [] elems;
    return 0;
}
