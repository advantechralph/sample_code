#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
static float _genRand(void);
static float _genRandFixed(int); 
static float _genRandFloat(float, float, int);
static float genRand(void);
static float genRandFloat(float min, float max);
static int genRandInt(int, int);
int main(void){
  float min=0, max=5;
  int i=0; 
  printf("%s: %d\n", __FUNCTION__, __LINE__);
  for(i=0; i<100; i++){
    float _n=_genRandFixed(3); 
    printf("%.3f  ", _n);
#if 0
    if(_n==0){
      printf("hunt 0!!\n");
    }
    if(_n==1){
      printf("hunt 1!!\n");
    }
#endif
    if(_n<0||_n>1){
      printf("_genRandFixed error!!\n");
      break;
    }
  }
  printf("%s: %d\n", __FUNCTION__, __LINE__);
  for(i=0; i<100; i++){
    //float n=_genRand((float)min,(float)max); 
    float _n=genRandFloat(0,5); 
    printf("%.3f  ", _n);
    if(_n==5){
      printf("hunt max!!\n");
      break; 
    }
  }
  printf("%s: %d\n", __FUNCTION__, __LINE__);
  for(i=0; i<100; i++){
    int _n=genRandInt(0,10);
    printf("%d  ", _n);
  }
  return 0; 
}
float _genRand(void){
  struct timeval now; 
  gettimeofday(&now, NULL);
  srand(now.tv_usec); 
  return (float)((float)rand()/(float)(RAND_MAX));
}
float genRand(void){
  return _genRandFixed(2);
}
static unsigned int _pwrTab[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
float _genRandFixed(int fixed){
  float n=_genRand(); 
  n+=(float)((float)5/(float)(_pwrTab[fixed+1]));
  return (float)(((int)(n*_pwrTab[fixed]))/(float)_pwrTab[fixed]);
}
float _genRandFloat(float min, float max, int fixed){
  float n=_genRandFixed(fixed);
  return ((float)(float)(n*(max-min))+(float)min);
}
float genRandFloat(float min, float max){
  float n=genRand();
  return ((float)(float)(n*(max-min))+(float)min);
}
int genRandInt(int min, int max){
  return (int)((genRandFloat(min, max)*10)/10); 
}
