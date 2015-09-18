#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(int argc, char* argv[])
{
    int seen_before[MAX] = {0};
    int arr[10], j = 0;   
    int i=0, rnd;
    while(i<10) 
    {
        rnd = rand() % MAX+ 1;
        printf("random index = %d\n", rnd);
        if ( seen_before[rnd-1] == 0 ) 
        {
            arr[i] = rnd;
            printf("arr[%d] = %d\n", i, arr[i++]);
            seen_before[rnd-1] = 1;
        }
        j++;
    }
    printf("j = %d\n", j);
    return 0;
}
