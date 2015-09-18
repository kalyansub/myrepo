#include "dq.h"

Deque::Deque()
{
    front = NULL;
    rear = NULL;
    count = 0;
}      

Deque::~Deque()
{
}
  
void Deque::InsertFront(int element)
{
    // Create a new node
    Node* tmp = new Node();
    tmp->data = element;
    tmp->next = NULL;
    tmp->prev = NULL;

    if ( isEmpty() ) {
        // Add the first element
        front = rear = tmp;
    }
    else {
        // Prepend to the list and fix links
        tmp->next = front;
        front->prev = tmp;
        front = tmp;
    }

    count++;
}

int Deque::RemoveFront()
{
    if ( isEmpty() ) {
        throw new DequeEmptyException();
    }

    //  Data in the front node
    int ret = front->data;

    // Delete the front node and fix the links
    Node* tmp = front;
    if ( front->next != NULL )
    {
        front = front->next;
        front->prev = NULL;
    }
    else
    {
        front = NULL;
    }
    count--;
    delete tmp;

    return ret;
}

void Deque::InsertBack(int element)
{          
    // Create a new node
    Node* tmp = new Node();
    tmp->data = element;
    tmp->next = NULL;
    tmp->prev = NULL;

    if ( isEmpty() ) {
        // Add the first element
        front = rear = tmp;
    }
    else {
        // Append to the list and fix links
        rear->next = tmp;
        tmp->prev = rear;
        rear = tmp;
    }

    count++;
}

int Deque::RemoveBack()
{
    if ( isEmpty() ) {
        throw new DequeEmptyException();
    }

    //  Data in the rear node
    int ret = rear->data;

    // Delete the front node and fix the links
    Node* tmp = rear;
    if ( rear->prev != NULL )
    {
        rear = rear->prev;
        rear->next = NULL;
    }
    else
    {
        rear = NULL;
    }
    count--;
    delete tmp;

    return ret;
}
  
int Deque::Front()
{          
    if ( isEmpty() )
        throw new DequeEmptyException();

    return front->data;
}

int Deque::Back()
{
    if ( isEmpty() )
        throw new DequeEmptyException();

    return rear->data;
}
  
int Deque::Size()
{
    return count;
}

bool Deque::isEmpty()
{
    return count == 0 ? true : false;
}

