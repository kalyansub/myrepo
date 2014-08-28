#include <stdio.h>
#include <stdlib.h>

int countIntInList(NodePtr head, int val)
{
    int count = 0;
    NodePtr cur = head;

    while( cur != NULL)
    {
        if (cur->data == val)
        { 
            count++;
        }
        cur = cur->next;
    }
    return count;
}
