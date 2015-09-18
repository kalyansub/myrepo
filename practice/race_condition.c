#include <assert.h>
#include <stdio.h>
#include <pthread.h>
 
static void * increment(void *);

int main(int argc, char* argv[])
{
    int count = 0; // initialize the counter
    const int num_threads = 2;
    pthread_t tid[num_threads];
    int error;
    int i;

    for(i = 0; i < num_threads; i++) // create all threads
    {
        error = pthread_create(&tid[i], 0, &increment, (void *)(&count));
        assert(error == 0);
    }
    for(i = 0; i < num_threads; i++) // wait for every thread
    {
        error = pthread_join(tid[i], NULL);
        assert(error == 0);
    }
    printf("main(): %d\n", count); // print the counter
    return 0;
}
static void * increment(void * count)
{
    (*((int *)count))++; // increment the counter
    return NULL;
}

