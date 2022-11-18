#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h>
void *PrintHello(void *threadid)
{
  printf("Hello World! It's me, thread #%ld!\n", (long) threadid);
  pthread_exit(NULL);
}
int main (int argc, char *argv[])
{
  int i, rc, nThreads;
  void * status;
  nThreads = atoi (argv[1]);
  pthread_t threads[nThreads];
  for(i = 0; i < nThreads; i++){
      printf("In main: creating thread %ld\n", i);
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
      /*        rc = pthread_join(thread[i], NULL);  */
    }
}
