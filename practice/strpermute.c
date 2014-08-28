/* Algorithm to find all permutations of a given input string; e.g., given ABC, the
   output should be: {ABC, ACB, CAB, CBA, BAC, BCA}; from basic math, the number of
   permutations of 'n' elements is n!. So this is an exponential time algorithm.
   The solution presented here is a recursive implementation of the 'permute' function
   with "backtracking:. ref. geeksforgeeks.org for a puciture of a recursion tree 
   
   $Author$: Kalyan Subramanian
   $Date$: Aug 26, 2014
   $email$: kalyan dot sub at gmail

*/
#include <stdio.h>

/* Helper routine to swap values at two pointers */
void swap(char* a, char* b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
} 

/* This function generates all permutations of an input string.
   It takes there input parameters:
   1. The string to permute
   2. starting index of the string
   3. ending index of the string
*/
void permute(char* a, int startIndex, int endIndex)
{
    int j;
    if (startIndex == endIndex)
    {
        printf("%s\n", a);
    }
    else
    {
        for(j = startIndex; j <= endIndex; j++)
        {
            swap((a+startIndex), (a+j));
            permute(a, startIndex+1, endIndex);
            swap((a+startIndex), (a+j));// backtracking step 
        }
    }

}

/* Main test program for permute: */
int main(int argc, char* argv[])
{
   char a[] = "ABC";
   permute(a,0,2); 
   return 0;
}
