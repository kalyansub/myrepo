/* Write a function to detect if a singly linked list has a loop in it.
 * If a loop exists, print true and remove the loop.
 *
 * (Interview question at Roku, NFLIX etc.) 
 *
 * Node1 ---> Node2 ---> Node3 --> Node4 
 *  (20)        ^ (4)     (15)      | (10)
 *              |                   |
 *              |------- Node5 <----|
 *                        (30)
 * There are many different algorithms to detect a loop:
 * 1. Use Hashing: traverse list one node at a time, storing the
 *    address of each node in a hash table. If the next ptr of hte
 *    current node points to any of the previously stored nodes in
 *    the hash table, return true, else if the next pointer reaches 
 *    NULL, return false.
 *
 * 2. Mark visited nodes: needs an extra field in the linked list structure
 *    called "visitied_flag" initialized to flase, and keep marking visited 
 *    nodes as true. If you see a node that already has its "visited_flag" set, 
 *    then this is the loop node. This is O(n) time complexity and O(n) space.
 *
 * 3. Floyd's cycle-finding algorithm:
 *    This is the fastest method. Traverse the linked list using a slow and a
 *    fast pointer. Move the slow pointer by one step and the fast by 2 steps
 *    at a time. If these pointers are equal at some point, this is the loop
 *    node. If the slow and fast pointers never meet, there is no loop.
 *    In this function, I implement the Floyd algorithmas above.
 *
 *    $Author$: Kalyan Subramanian
 *    $Date$: September 10, 2014
 *    $emai$: kalyan dot sub at gmail dot com
 *
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* Define linked list node structure */

typedef struct node
{
   int data;
   struct node* next;
} Node;

typedef struct node* NodePtr;
typedef struct node** NodeRef;

//Function prototype declarations
int detect_and_remove_loop(NodePtr list);
void remove_loop(NodePtr loop_node, NodePtr head);
void push_back(NodeRef head_ref, int new_data);
void printList(NodePtr node);

/* This function detects and removes loop in the list
 *   using two pointers, slow_ptr and fast_ptr, with fast advancing 2 nodes
 *   at a time and slow advancing only 1 node at a time. If fast_ptr equals
 *   the slow_ptr at any stage, a loop is detected.
 *   Input: Pointer to head of linked list in which we seek to detect a loop
 *   Output: if a loop is detected, it returns 1, else it returns 0 
 *   Calls: remove_loop to break the loop
 */
int detect_and_remove_loop(NodePtr list)
{
    NodePtr slow_ptr = list, fast_ptr = list;
    int retVal = 0;

    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next; //advance one node at a time
        fast_ptr = fast_ptr->next->next; // advance 2 nodes at a time
        if (slow_ptr == fast_ptr)
        {
            printf("Loop detected at: %d\n", slow_ptr->data);
            remove_loop(slow_ptr, list); 
            retVal = 1;
        }
    }
    return retVal;
}


/* Function to remove a loop in a singly linked list. 
 * Inputs: ptr to loop_node i.e., the node where a loop is detected
 *         pointer to the head or start node of the singly linked list
 * /
void remove_loop(NodePtr loop_node, NodePtr head)
{
    NodePtr ptr1, ptr2;
    
    ptr1 = head; // start at the head of the linked list and move to next node
    while(1)
    {
        ptr2 = loop_node; // set a pointer to the loop node and check if it ever reaches head
        while( ptr2->next != loop_node && ptr2->next != ptr1)
        {
            ptr2 = ptr2->next;
        }
        if( ptr2->next = ptr1) // if ptr2 reached ptr1, there is a loop break it at ptr2
        {
            break;
        }
        else
        {
           // if ptr2 didnt reach ptr1, then try the next node after ptr1
            ptr1 = ptr1->next;
        }
        // At the end of loop ptr2 is the last node of the loop. So
        // set the next ptr of ptr2 to NULL 
        ptr2->next = NULL;
    }
}

void push_back(NodeRef head_ref, int new_data)
{
    NodePtr new_node = (NodePtr)malloc(sizeof(Node)); //allocate new node
    assert(new_node != NULL);
    new_node->data = new_data; // insert the data 
    new_node->next = (*head_ref); // link the old list off the new node
    (*head_ref)    = new_node; // move head to point to new node
}
/* 
 * Utility function to print the list contents: 
 *
 */
void printList(NodePtr node)
{
    int i = 0;
    while(node != NULL)
    {
       printf("List element %d: (%d)\n", i++, node->data);
       node = node->next;
    }
    
}

/* Main test program to test loop detection */
int main(int argc, char* argv[])
{
    NodePtr head;
    int    has_loop;

    push_back(&head, 20);
    push_back(&head, 4);
    push_back(&head, 15);
    push_back(&head, 10);
    push_back(&head, 30);

    /* Create a loop for testing the detection code: */
    head->next->next->next->next->next = head->next->next;
    
    has_loop = detect_and_remove_loop(head);
    getchar();
    printf("After removing loop the contents are:\n");
    printList(head);

    return 0;
}

