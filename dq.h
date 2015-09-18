#ifndef DQ_H
#define DQ_H

#ifndef __cplusplus
#error a C++ compiler is required
#endif

#include <iostream>

class DequeEmptyException
{
public:
    DequeEmptyException()
    {
	    std::cout << "Deque empty" << std::endl;
    }
};

// Each node in a doubly linked list
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque
{

public:
    Deque();
    ~Deque();
    void InsertFront(int element);
    int RemoveFront();
    void InsertBack(int element);
    int RemoveBack();
    int Front();
    int Back();
    int Size();
    bool isEmpty();

private:
    //Disallow copy contructor and assigment operator:
    Deque(const Deque& other);
    Deque operator=(const Deque& rhs);
    Node* front;
    Node* rear;
    int count;
};
#endif //DQ_H
