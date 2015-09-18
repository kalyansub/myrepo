#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;

    for( i = 0 ; i < 100; i++)
    {
        if (i & 0x0001 ) 
        {  
            printf("%d\n", i);
        }
    }
    return 0;
}
