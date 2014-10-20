/* Determine if the stack on your machine grows upwards or downwards. 
 * Clearly, machine and compiler dependenet, so no generic asnwer possible ...
 * $Author$: Kalyan Subramanian
 * $Date$: Sept 16, 2014
 * $email$: kalyan dot sub at gmail dot com
 */

#include <stdio.h>

void test_stack_growth_direction(int recursion_depth)
{
  int var;

  printf("%p\n", &var);

  if (recursion_depth < 5) 
  {
    test_stack_growth_direction(recursion_depth + 1);
  }
}

int main( int argc, char* argv[]) 
{
  test_stack_growth_direction(0);
}
