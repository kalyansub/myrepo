/* Hacker's delight bitCount function written in terms of bitwise constanrs in binary
 * instead of hex constants, which make it a little obscure...:
 * The first step adds the even bits to the odd bits, producing a sum of bits in each
 * two. The other steps add high-order chunks to low-order chunks, doubling the chunk
 * size all the way up, until we have the final count taking up the entire int.
 */

#include <stdio.h>

#define ONE_BIT_SET         0b01010101010101010101010101010101
#define TWO_BITS_SET        0b00110011001100110011001100110011
#define FOUR_BITS_SET       0b00001111000011110000111100001111
#define EIGHT_BITS_SET      0b00000000111111110000000011111111  
#define SIXTEEN_BITS_SET    0b00000000000000001111111111111111

unsigned int bitCount(unsigned int x)
{
  x = (((x >> 1) & ONE_BIT_SET)
       + (x      & ONE_BIT_SET));
  x = (((x >> 2) & TWO_BITS_SET)
       + (x      & TWO_BITS_SET)); 
  x = (((x >> 4) & FOUR_BITS_SET)
       + (x      & FOUR_BITS_SET)); 
  x = (((x >> 8) & EIGHT_BITS_SET)
       + (x      & EIGHT_BITS_SET)); 
  x = (((x >> 16)& SIXTEEN_BITS_SET)
       +(x       & SIXTEEN_BITS_SET)); 

  return x;
}

int main(int argc, char* argv[])
{
    unsigned int x = 0b1111000011110000000000000001111;

    printf("1's population count of x = %d\n", bitCount(x));
    return 0;
}
