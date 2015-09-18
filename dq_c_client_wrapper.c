#include "dq_c_wrapper.h"
#ifndef __cplusplus
#include <stdio.h>
#include <stdlib.h>
#endif

void dq_c_client_test_driver()
{
    Deque* q1 = create_Deque();
    int r1,r2,r3,r4;

    if (q1 != NULL)
    {
        InsertFront(q1, 100);
        InsertFront(q1, 200);
        InsertFront(q1, 300);
        InsertFront(q1, 400);
        
        r1 = RemoveBack(q1);
	printf("r1 = %d\n", r1);
        r2 = RemoveBack(q1);
	printf("r2 = %d\n", r2);
        r3 = RemoveBack(q1);
	printf("r3 = %d\n", r3);
        r4 = RemoveBack(q1);
	printf("r4 = %d\n", r4);
    }
    else
    {
        printf("create_Deque() failed!\n");
        exit(-1);
    }
    destroy_Deque(q1);

}

