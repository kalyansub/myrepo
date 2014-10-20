/* Write a function to print all even numbers from one thread and odd numbers in
 *   another thread. The output must be in sequence (e.g., 0,1,2,3,4,5,6,7,8,9,10..)
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

void *function1();
void *function2();
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;
int my_turn = 0;

int main(int argc, char* argv[])
{
   int rc1, rc2;
   pthread_t thread1, thread2;

   pthread_cond_init(&cond, NULL);

   /* Create independent threads each of which will execute function1 and 2*/
   if( (rc1=pthread_create( &thread1, NULL, &function1, NULL)) )
   {
      printf("Thread creation failed: %d\n", rc1);
   }

   if( (rc2=pthread_create( &thread2, NULL, &function2, NULL)) )
   {
      printf("Thread creation failed: %d\n", rc2);
   }

   /* Wait till threads are complete before main continues. Unless we  */
   /* wait we run the risk of executing an exit which will terminate   */
   /* the process and all threads before the threads have completed.   */

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   pthread_mutex_destroy(&lock);
   pthread_cond_destroy(&cond);

   exit(0);
}

void* function1(void* arg)
{
    int i;
    pthread_t tid;
    
    tid = pthread_self();

    printf("Thread fucntion1: thread id = 0x%04x\n", (unsigned int)tid);
    for(i = 0; i <= MAX; i+=2)
    {
        pthread_mutex_lock(&lock);
        while (my_turn != 0)
        {
            pthread_cond_wait(&cond, &lock);
        }
        printf("Thread1 for even numbers: %d\n", i);
        my_turn = 1;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond);
    }
}

void* function2(void)
{
    int i;
    pthread_t tid;
    tid = pthread_self();

    printf("Thread fucntion2: thread id = 0x%04x\n", (unsigned int)tid);
    for(i = 1; i < MAX; i+=2)
    {
        pthread_mutex_lock(&lock);
        while (my_turn != 1)
        {
            pthread_cond_wait(&cond, &lock);
        }
        printf("Thread2 for odd numbers: %d\n", i);
        my_turn = 0; 
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond);
   }
}
