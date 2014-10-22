/* Write a function to swap the bits in odd positions with the bits in even positions in an int.
 * $Author$: Kalyan Subramanian
 * $Date$: Oct 22, 2014
 * $email$: kalyan dot sub at gmail dot com
 */
#include <stdio.h>

#define EVEN_MASK 0xAAAAAAAA
#define ODD_MASK  0x55555555

void printbin(unsigned int n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
    {
        (n & i)? printf("1"): printf("0");
    }
    printf("\n");
}

int swapOddEvenBits(int input)
{
    int res;
    res = ((input & EVEN_MASK) >> 1)|((input & ODD_MASK) << 1);
    return res;
}

int main(int argc, char* argv[])
{
    int num = 0b10101111001100110011110011010110;

    printf("Even bit mask is : ");
    printbin(EVEN_MASK); 
    printf("Odd bit mask is :  ");
    printbin(ODD_MASK); 

    printf("Original number: ");
    printbin(num);
    printf("Swapped number:  "); 
    printbin(swapOddEvenBits(num));

    return 0;
}
