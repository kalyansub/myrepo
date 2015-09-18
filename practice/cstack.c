#include <stdio.h>
#include <stdlib.h>  /* for dynamic allocation */
#include <assert.h>
#include "cstack.h"       

/************************ Function Definitions **********************/

void StackInit(stackT *stackptr, int maxSize)
{
  assert(stackptr != NULL);

  stackptr->contents = (stackElementT *)malloc(sizeof(stackElementT) * maxSize);

  if (stackptr->contents == NULL) 
  {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);  /* Exit, returning error code. */
  }
  stackptr->maxSize = maxSize;
  stackptr->top = -1;  /* i.e., empty */
}

void StackDestroy(stackT *stackptr)
{
  assert(stackptr != NULL);

  /* Get rid of array. */
  free(stackptr->contents);

  stackptr->contents = NULL;
  stackptr->maxSize = 0;
  stackptr->top = -1;  /* i.e., empty */
}

void StackPush(stackT *stackptr, stackElementT element)
{
  assert(stackptr != NULL);

  if (StackIsFull(stackptr))
  {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);  /* Exit, returning error code. */
  }

  /* Put information in array; update top. */

  stackptr->contents[++stackptr->top] = element;
}

stackElementT StackPop(stackT *stackptr)
{
  if (StackIsEmpty(stackptr)) 
  {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);  /* Exit, returning error code. */
  }

  return stackptr->contents[stackptr->top--];
}

int StackIsEmpty(stackT *stackptr)
{
  return stackptr->top < 0;
}

int StackIsFull(stackT *stackptr)
{
  return stackptr->top >= stackptr->maxSize - 1;
}
