/*  
 *  Simple program showing 2 threads with a mutex to access a shared counter variable.   
 *  IMPORTANT: Use the script "compile_with_pthreads" to build this example. gcc seems
 *  picky about the order in whinc the input, output and libpthread arguments appear!
 *  Enhanced to show two threads and two mutex variables that can cause a deadlock.

    $Author$: Kalyan Subramanian
    $email$: kalyan dot sub at gmail
    $Date$: Sep 17, 2014 
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function1();
void *function2();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
int  counter1 = 0;
int  counter2 = 0;

int main(int argc, char* argv[])
{
   int rc1, rc2;
   pthread_t thread1, thread2;

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

   exit(0);
}

void *function1()
{
   pthread_t tid;
   tid = pthread_self();
   printf("### In thread function1, with thread ID: 0x%x\n", (int)tid);

   pthread_mutex_lock( &mutex1 );
   printf("### Thread1, locked mutex1\n");
   counter1++;
   printf("\t ### Counter 1 value: %d\n",counter1);

   pthread_mutex_lock( &mutex2 );
   printf("\t ### Thread1, locked mutex2\n");
   counter2--;
   counter1++;
   printf("\t ### Counter 2 value: %d\n",counter2);
   printf("\t ### Counter 1 value: %d\n",counter1);

   pthread_mutex_unlock( &mutex2 );
   printf("\t ### Thread1, UNlocked mutex2\n");
   pthread_mutex_unlock( &mutex1 );
   printf("### Thread1, UNlocked mutex1\n");
}

void *function2()
{
   pthread_t tid;
   tid = pthread_self();
   printf("@@@ In thread function2, with thread ID: 0x%x\n", (int)tid);

   pthread_mutex_lock( &mutex2 );
   printf("@@@ Thread2, locked mutex2\n");
   counter2++;
   printf("\t @@@ Counter 2 value: %d\n",counter2);

   pthread_mutex_lock( &mutex1 );
   printf("\t @@@ Thread2, locked mutex1\n");
   counter1--;
   counter2++;
   printf("\t @@@ Counter 1 value: %d\n",counter1);
   printf("\t @@@ Counter 2 value: %d\n",counter1);

   pthread_mutex_unlock( &mutex1 );
   printf("\t @@@ Thread2, UNlocked mutex1\n");
   pthread_mutex_unlock( &mutex2 );
   printf("@@@ Thread2, UNlocked mutex2\n");
}
