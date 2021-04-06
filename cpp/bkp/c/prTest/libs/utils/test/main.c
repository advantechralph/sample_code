#include "utils.h"
int main(int argc, char *argv[]){
  char buf[32]={0}; 
  long start, end; 
  randString(buf, 10);
  start=getNow();
  printf("start time: %ld\n", start);
  printf("%s\n", buf);
  printf("randStringAlloc=%s\n", randStringAlloc(20));
  printf("rand()=%d\n", rand());
  end=getNow();
  printf("end time: %ld\n", end);
  printf("time interval: %ld\n", (end-start));
  return 0; 
}
