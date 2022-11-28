#include <math.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>
// double a[3];
void fun(float b) {
  FILE *ptr = NULL;
  ptr = fopen("1.txt", "a");
  fprintf(ptr, "%lf\n", b);
}
void dun() {
  for (long long int i = 1; i <= pow(2, 32); ++i) {
  }
}

void *threadA() { dun(); }
void *threadB() { dun(); }
void *threadC() { dun(); }

int main(int argc, char *argv[]) {

  pthread_t A;
  pthread_t B;
  pthread_t C;

  struct timespec t1, t2;

  clock_gettime(CLOCK_REALTIME, &t1);
  pthread_create(&A, NULL, threadA, NULL);
  pthread_create(&A, NULL, threadB, NULL);
  pthread_create(&A, NULL, threadC, NULL);
  pthread_setschedparam(A, SCHED_OTHER, NULL);
  // nice(0);
  pthread_join(A, NULL);
  clock_gettime(CLOCK_REALTIME, &t2);
  double tym;
  tym = (double)((t2.tv_nsec - t1.tv_nsec)) / CLOCKS_PER_SEC;
  fun(tym);
  
  for(int v=1;v<=6;++v){
     clock_gettime(CLOCK_REALTIME, &t1);
    pthread_setschedprio(A, v);
    pthread_join(A, NULL);
    clock_gettime(CLOCK_REALTIME, &t2);
    tym = (double)((t2.tv_nsec - t1.tv_nsec)) / CLOCKS_PER_SEC;
    fun(tym);
  }

  clock_gettime(CLOCK_REALTIME, &t1);
  pthread_create(&B, NULL, threadA, NULL);
  pthread_create(&B, NULL, threadB, NULL);
  pthread_create(&B, NULL, threadC, NULL);
  pthread_setschedparam(B, SCHED_RR, NULL);
  pthread_join(B, NULL);
  clock_gettime(CLOCK_REALTIME, &t2);

  tym = (double)((t2.tv_nsec - t1.tv_nsec)) / CLOCKS_PER_SEC;
  fun(tym);
  for(int v=1;v<=6;++v){
    clock_gettime(CLOCK_REALTIME, &t1);
    pthread_setschedprio(B, v);
    pthread_join(B, NULL);
    clock_gettime(CLOCK_REALTIME, &t2);
    tym = (double)((t2.tv_nsec - t1.tv_nsec)) / CLOCKS_PER_SEC;
    fun(tym);
  }

  clock_gettime(CLOCK_REALTIME, &t1);
  pthread_create(&C, NULL, threadA, NULL);
  pthread_create(&C, NULL, threadB, NULL);
  pthread_create(&C, NULL, threadC, NULL);
  pthread_setschedparam(C, SCHED_FIFO, NULL);
  pthread_join(C, NULL);
  clock_gettime(CLOCK_REALTIME, &t2);
  tym = (double)((t2.tv_nsec - t1.tv_nsec)) / CLOCKS_PER_SEC;
  fun(tym);
  // int x=sched_rr_get_interval(threadB,);

  // for priroity
  // fun(-1.0);
  for(int v=1;v<=6;++v){
    clock_gettime(CLOCK_REALTIME, &t1);
    pthread_setschedprio(C, v);
    pthread_join(C, NULL);
    clock_gettime(CLOCK_REALTIME, &t2);
    tym = (double)((t2.tv_nsec - t1.tv_nsec)) / CLOCKS_PER_SEC;
    fun(tym);
  }

  

  exit(0);

  return 0;
}