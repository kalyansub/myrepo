/* This code shows a classic thread deadlock problem in action:
 * Two threads acquire 2 different mutxes in different order and release them in the order each 
 * of them acquired their mutexes. This leads to one waiting for another to release the mutex that
 * it needs to proceed. The two threads are main() and simple_thread() in this case.
 * $Author$: Kalyan Subramanian
 * $Date$: Sept 26, 2014
 * $email$: kalyan dot sub at gmail
 *
 */

#include <stdio.h>
#include <assert.h>
#include <pthread.h>

static void * simple_thread(void *);

pthread_mutex_t mutex_1= PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t mutex_2= PTHREAD_MUTEX_INITIALIZER;

int counter1 = 0;
int counter2 = 0;


int main(int argc, char* argv[])
{
    pthread_t tid = 0;
    int retVal;

// create a thread
    retVal = pthread_create(&tid, NULL, &simple_thread, NULL);
    assert(retVal == 0);

    retVal = pthread_mutex_lock(&mutex_1); // acquire mutex_1
    assert(retVal == 0);
    counter1++;
    printf("main() thread: counter1 = %d\n", counter1);

    retVal = pthread_mutex_lock(&mutex_2); // acquire mutex_2
    assert(retVal == 0);
    counter2--;
    printf("main() thread: counter2 = %d\n", counter1);

    retVal = pthread_mutex_unlock(&mutex_2); // release mutex_2
    assert(retVal == 0);

    retVal = pthread_mutex_unlock(&mutex_1); // release mutex_1
    assert(retVal == 0);

    retVal = pthread_join(tid, NULL); 
    assert(retVal == 0);

    return 0;
}


static void * simple_thread(void * dummy)
{
    int retVal = pthread_mutex_lock(&mutex_2); // acquire mutex_2
    assert(retVal == 0);
    counter2++;
    printf("Second thread: counter2 = %d\n", counter2);

    retVal = pthread_mutex_lock(&mutex_1); // acquire mutex_1
    assert(retVal == 0);
    counter1--;
    printf("Second thread: counter2 = %d\n", counter2);

    retVal = pthread_mutex_unlock(&mutex_1); // release mutex_1
    assert(retVal == 0);
    
    retVal = pthread_mutex_unlock(&mutex_2); // release mutex_2
    assert(retVal == 0);
    
    return NULL;
}
