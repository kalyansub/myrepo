#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    FILE* fpIn;
    int x, sum = 0, counter = 0, max = INT_MIN;

    fpIn = fopen("ints.txt", "r");
    //printf("size of int on this arch: (%d) bytes\n", (int)(sizeof(int)));

    if( fpIn != NULL )
    {
        while(1)
        {
            fscanf(fpIn, "%d", &x);
            if ( feof(fpIn) )
            {
                break;
            }
            max = (x >= INT_MIN) ? x: INT_MIN;
            sum += x; 
            ++counter;
        }
        printf("Sum of all %d integers read = %d, maximum value = %d\n", counter, sum, max);
    }
    else
    {
        printf("Unable to open input file ints.txt\n");
        return -1;
    }
    fclose(fpIn);
    return 0;
}
