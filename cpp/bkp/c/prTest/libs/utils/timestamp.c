#include "utils.h"

unsigned long getNow(void){
  struct timeval now; 
  gettimeofday(&now, NULL);
  return now.tv_sec*1000000+now.tv_usec;
}

void dumpNow(void){
#if 0
  printf("now: %lu\n", getNow());
#else
  struct timeval now;
  gettimeofday(&now, NULL);
  struct tm *ptm=localtime(&now.tv_sec);
  printf("now: %04d-%02d-%02d %02d:%02d:%02d:%ld\n", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, now.tv_usec);
#endif
}

