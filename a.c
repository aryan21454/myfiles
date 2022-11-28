#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>

void *funcone() {
  for (long long int i = 0; i < pow(2, 32); i++) {
  }
}
void *functwo() {
  for (long long int i = 0; i < pow(2, 32); i++) {
  }
}

void *functhree() {
  for (long long int i = 0; i < pow(2, 32); i++) {
  }
}
int main() {
  pthread_t firstthread;
  pthread_t secondthread;
  pthread_t thirdthread;
  struct timespec ppf;
  struct timespec llb;
  struct sched_param param;

  FILE *pointt;
  pointt = fopen("mydata.txt", "a");

  clock_gettime(CLOCK_REALTIME, &ppf);

  pthread_create(&firstthread, NULL, funcone, NULL);
  pthread_create(&firstthread, NULL, functwo, NULL);
  pthread_create(&firstthread, NULL, functhree, NULL);
  pthread_setschedparam(firstthread, SCHED_OTHER, &param);
  pthread_join(firstthread, NULL);

  clock_gettime(CLOCK_REALTIME, &llb);
  fprintf(pointt, " %f\n",
          ((double)(llb.tv_nsec - ppf.tv_nsec)) / CLOCKS_PER_SEC);

  clock_gettime(CLOCK_REALTIME, &ppf);

  pthread_create(&secondthread, NULL, funcone, NULL);
  pthread_create(&secondthread, NULL, functwo, NULL);
  pthread_create(&secondthread, NULL, functhree, NULL);
  pthread_setschedparam(secondthread, SCHED_RR, &param);

  pthread_join(secondthread, NULL);

  clock_gettime(CLOCK_REALTIME, &llb);
  fprintf(pointt, "%f\n",
          ((double)(llb.tv_nsec - ppf.tv_nsec)) / CLOCKS_PER_SEC);
  clock_gettime(CLOCK_REALTIME, &ppf);

  pthread_create(&thirdthread, NULL, funcone, NULL);
  pthread_create(&thirdthread, NULL, functwo, NULL);
  pthread_create(&thirdthread, NULL, functhree, NULL);
  pthread_setschedparam(thirdthread, SCHED_FIFO, &param);
  pthread_join(thirdthread, NULL);

  clock_gettime(CLOCK_REALTIME, &llb);
  fprintf(pointt, "%f\n",
          ((double)(llb.tv_nsec - ppf.tv_nsec)) / CLOCKS_PER_SEC);

  for (int mynum = 1; mynum <= 6; mynum++) {

    clock_gettime(CLOCK_REALTIME, &ppf);

    pthread_create(&firstthread, NULL, funcone, NULL);
    pthread_create(&firstthread, NULL, functwo, NULL);
    pthread_create(&firstthread, NULL, functhree, NULL);
    pthread_setschedparam(firstthread, SCHED_OTHER, &param);
    nice(0);
    pthread_join(firstthread, NULL);

    clock_gettime(CLOCK_REALTIME, &llb);

    fprintf(pointt, " %f\n",
            ((double)(llb.tv_nsec - ppf.tv_nsec)) / CLOCKS_PER_SEC);

    clock_gettime(CLOCK_REALTIME, &ppf);
    pthread_setschedprio(secondthread, mynum);
    pthread_join(secondthread, NULL);
    clock_gettime(CLOCK_REALTIME, &llb);

    fprintf(pointt, "%f\n",
            ((double)(llb.tv_nsec - ppf.tv_nsec)) / CLOCKS_PER_SEC);
    clock_gettime(CLOCK_REALTIME, &ppf);
    pthread_setschedprio(thirdthread, mynum);
    pthread_join(thirdthread, NULL);
    clock_gettime(CLOCK_REALTIME, &llb);

    fprintf(pointt, "%f\n",
            ((double)(llb.tv_nsec - ppf.tv_nsec)) / CLOCKS_PER_SEC);
  }

  fclose(pointt);
  exit(0);
}
