#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>

void test2(void){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  struct tm *ptm=localtime(&tv.tv_sec);
  printf("now: %04d-%02d-%02d %02d:%02d:%02d:%ld\n", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, tv.tv_usec);
}

void test1(void){
  time_t t=time(NULL);
  struct tm *ptm=localtime(&t);
  printf("now: %04d-%02d-%02d %02d:%02d:%02d\n", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
}

int main(void){
  test2();
  test1();
  return 0; 
}

