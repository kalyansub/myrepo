#include<stdio.h>
 
/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
 
/* Program to test function countSetBits */
int main()
{
    int i = 112348;
    printf("%d has %d bits set to 1\n", i,countSetBits(i));
    getchar();
    return 0;
}
