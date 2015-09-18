#include <stdio.h>
#include <string.h>  /* for strlen() */
#include "cstack.h"

#define MAX 11

int main(void)
{
  stackT stack;    /* A stack to hold characters. */
  char str[MAX];   /* String entered by user. */
  char *traverse;  /* Pointer used to traverse the string. */

  /*
   * Get a string from the user--don't enter more
   * than 10 characters!
   */
  printf("Enter a string <= 10 chars: ");

  fgets(str, MAX, stdin);  /* Read line, discard newline. */

  /*
   * Initialize the stack.  Make it at least
   * big enough to hold the string we read in.
   */
  StackInit(&stack, strlen(str));

  /*
   * Traverse the string and put each
   * character on the stack.
   */

  for (traverse = str; *traverse != '\0'; traverse++) 
  {
    printf("Pushing: %c on to stack\n", *traverse);
    StackPush(&stack, *traverse);
    printf("Popped: %c from top of stack\n", StackPop(&stack));
  }

  /*
   * Pop each of the characters off of
   * the stack and print them out.
   */

  /*
  printf("\nPopped characters are: ");

  while (!StackIsEmpty(&stack)) {
    printf("%c", StackPop(&stack));
  }
  */

  printf("\n");

  StackDestroy(&stack);

  return 0;
}
