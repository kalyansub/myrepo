#include "dq_c_wrapper.h"
#include "dq.h"

Deque* create_Deque( ) 
{
    return static_cast<Deque*>(new Deque());
}

void destroy_Deque( Deque* This )
{
    delete This;
}
void InsertFront(Deque* This, int element)
{
    This->InsertFront(element);
}
int RemoveFront(Deque* This)
{
    return This->RemoveFront();
}
void InsertBack(Deque* This, int element)
{
    This->InsertBack(element);
}
int RemoveBack(Deque* This)
{
    return This->RemoveBack();
}
int Front(Deque* This)
{
    return This->Front();
}
int Back(Deque* This)
{
    return This->Back();
}

int Size(Deque* This)
{
    return This->Size();
}

bool isEmpty(Deque* This)
{
    return This->isEmpty();
}
