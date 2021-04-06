#include "main.h"
#include "timer.h"
float test5Rand(float min, float max){
  struct timeval now; 
  gettimeofday(&now, NULL);
  srand(now.tv_usec); 
  return ((float)((float)rand()/(float)(RAND_MAX))*(max-min)+min);
}
void test5(void){
  unsigned long start=0, end=0; 
  int num=1000; 
  start=getNow();
  for(int i=0; i<num; i++){
    float n=test5Rand(0,100);
    //printf("%f\n", test5Rand(0,100));
    if(n>100) printf("num: %d, %f over 100!!!\n", num, n); //impossible
  }
  end=getNow();
  printf("Generate Rand 0~100 %d times: %lu(μs)\n", num, end-start);
}
