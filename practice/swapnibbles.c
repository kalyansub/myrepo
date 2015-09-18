/* Interview problem: given a 8 bit integer, swap the 2 nibbles in a byte, e.g. 100 decimal is represented as  0110 0100, swap nibbles to get: 0100 0110, i.e. 70 decimal */


#include <stdio.h>

int swapNibbles(int x);

int swapNibbles(int x)
{
    return( ((x&0x0F)<<4)|((x&0xF0)>>4) );

}

int main(int argc, char* argv[])
{
   int x = 100;
   
   int y = 0;

   y = swapNibbles(x);
 

   printf("original number: %d, swapped nibbles gives: %d\n", x, y);

   return 0;
}
