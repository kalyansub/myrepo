/*  
    Fifo implmentation header : a simple array based character FIFO.   
     
    $Author$: Kalyan Subramanian
    $email$: kalyan dot sub at gmail
    $Date$: Sep 16, 2014 
*/
// A character fifo implementation using an array in C++; defines the class and interfaces
#ifndef __FIFO_H__
#define __FIFO_H__

#include <iostream>
#include <memory>

using std::cout;
using std::unique_ptr;

enum {MAX_NUM = 10};

class Fifo
{
    public:
      Fifo(unique_ptr<char[]> elements, int len);
      ~Fifo();
      void push(char ch);
      char pop(void);
      char print(void);
      inline bool isEmpty(void) { return (m_Size == 0)?true: false;}
      inline bool isFull(void)  { return (m_Size == MAX_NUM) ? true: false;} 

    private:
      // Disallow copy c'tor and assigment operator
      Fifo(const Fifo& rhs);
      Fifo& operator=(const Fifo& other);

      int m_CurPos;
      int m_Size;
      unique_ptr<char[]> m_Elements; 
      //char* m_Elements;
};
#endif//__FIFO_H__
