/* Program to detect if the machine is little endian or big endian; a little endian machine
   stores the lower order byte first (i.e., lower memory address), a big endian machine stores the higher order byte first (i.e., in the lower memory address).

  $Author$: Kalyan Subramanian
  $email$: kalyan dot sub at gmail dot com
  $Date$: Aug 24, 2014

*/
#include <stdio.h>

unsigned int EndianSwap(unsigned int num);


unsigned int EndianSwap(unsigned int num)
{
    unsigned int p1, p2, p3, p4 = 0, ret;
    
    p1 = (num & 0x000000ff) << 24;
    p2 = (num & 0x0000ff00) << 16;
    p3 = (num & 0x00ff0000) << 8;
    p4 = (num & 0xff000000);
    
    ret = (p1) | (p2 >> 8) | (p3 >> 16) | (p4 >> 24);
    
    return ret;
}

int main(int argc, char* argv[])
{
   unsigned int k, i = 0x1, j = 0x12345678;
    
    char* byte = (char*)(&i);

    printf("storing 0x%04x in memory...", j); 
    (*byte)? printf("Little endian\n"): printf("Big endian\n");

    printf("sizeof unsigned int = %d\n", (unsigned int)sizeof(j));
    for(k = 0; k < sizeof(j); k++)
    {
        byte = (char*)(&j) + k;
        printf("Memory location 0x%04x  = 0x%.2x\n", byte, *byte); 
    }
    i = EndianSwap(j); 
    for(k = 0; k < sizeof(j); k++)
    {
        byte = (char*)(&i) + k;
        printf("Endian swapped storage at memory location of 0x%04x = 0x%.2x\n", byte, *byte);
    }

   return 0;
}

