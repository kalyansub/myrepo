#include<stdio.h>
#include <time.h>
 
/* Function to get no of set bits in binary representation of passed binary no. 
 * Also, checks if the compiler can use a built-in intrinsic "__builtin_popcount" instruction.
 * For gcc on x86 arch, the flag needed for the compiler is "-msse4.2"
*/

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
    int i = (2>>30)|(2<<30)|(2>>29)|(2<<29)|(2>>28)|(2<<28)|(2<<24)|(2>>25);
    time_t start = time(NULL);
    printf("0x%04x has %d bits set to 1\n", i,countSetBits(i));
    time_t end = time(NULL);
    printf("C function takes %0.8f time\n",(float)(end-start));

    start = time(NULL);
    printf("Using built in gcc instrinsic popcount gives: %d\n", __builtin_popcount(i));
    end = time(NULL);
    double time = ((double)(end-start)/CLOCKS_PER_SEC)*1000000;
    printf("built-in instruction takes %0.8f time\n",time);

    getchar();
    return 0;
}
