#include <stdlib.h>
#include <stdio.h>
#define MAX 21

int main(int argc, char* argv[])
{
    time_t t;
    srand(time(t));
    
    int i, rand_num, min = 0;

    for (i = 0; i < MAX; i++)
    {
        rand_num = ((float)rand())/RAND_MAX*6 + min;
        printf("rand_num = %d\n", rand_num);
     }
    
    return 0;
}
