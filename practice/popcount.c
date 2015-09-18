#include <stdio.h>

int popcount(int value)
{
    int count = 0;

    while( value != 0 )
    {
        if( (value % 2) == 1)
        {
            count++;
        }
        value = value/2 ;
    }
   
    return count; 
}

int main(int argc, char* argv[])
{
    int values[] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535};
    int size = sizeof(values)/sizeof(values[0]);
    int j;

    for(j = 0; j < size; j++)
    {
        printf("Ones population count of values[%d] %d = %d\n", j, values[j], popcount(values[j])); 
    }


    return 0;
}
