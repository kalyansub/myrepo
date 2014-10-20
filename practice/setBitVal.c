#include <stdio.h>

int setBitVal(int range_low, int range_hi, char value)
{
   int i;

   for(i = range_low; i <= range_hi; i++)
   {
       value |= (1 << i); //set all bits from position range_low to range_hi
   }
   return value;
}

int clearBitVal(int range_low, int range_hi, char value)
{
    int i;
    for(i = range_low; i <= range_hi; i++)
    {
        value &= ~(1 << i);//clear all bits from position range_low to range_hi
    }
    return value;
}

int testIfSet(int range_low, int range_hi, char value)
{
    int i;
    unsigned int isSet = 0U;

    for(i = range_low; i <= range_hi; i++) /* check if any bits in given range are set & print them*/
    {
        isSet = value & (1 << i);
        if (isSet)
        {
             printf("%d th bit is set\n", i);
        }
        else
        {
            printf("%d th bit is not set\n", i);
        }
    } 
    return value;
}

int toggleBits(int range_low, int range_hi, int value)
{
    int i;

    for(i = range_low; i <= range_hi; i++) /* check if any bits in given range are set & print them*/
    {
        value ^= (1 << i);
        printf("Toggled %d th bit to:%d\n", i, value);
    }

    return value;
}

int main(int argc, char* argv[])
{
    int a = 0x03;

    a= setBitVal(3, 5, a);
    printf("%02x\n",a);

    a = clearBitVal(0, 3, a);
    printf("%02x\n",a); 

    a = 0x0f;
    a = testIfSet(0,7,a);
    printf("%02x\n",(unsigned)a); 

   a= 0x55;
   a = toggleBits(0,7,a);
   printf("%02x\n",(unsigned)a); 
    
    return 0;
}
