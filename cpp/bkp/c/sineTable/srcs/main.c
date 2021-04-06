#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

extern float sineTable[]; 

int factorial(int n){
  int _i=0;
  int _ans=1; 
  for(_i=1; _i<(n+1); _i++){
    _ans=_ans*_i;
  }
  return _ans; 
}

float power(float x, int n){
  int _i=0;
  float _ans=x; 
  for(_i=1; _i<n; _i++){
    _ans=x*_ans;
  }
  return _ans; 
}

float sineFunc(int theta){
  int _i=0, _theta=theta%360; 
  float radian=(3.1415926532*_theta)/180;
  float _ans=radian, _tmp=0; 
  for(_i=0; _i<5; _i++){
    _tmp=((float)power(radian, (3+2*_i))/factorial((3+2*_i)));
    if((_i%2)==0){
      _ans-=_tmp; 
    }else{
      _ans+=_tmp; 
    }
  }
  return _ans; 
}

int main(int argc, char *argv[]){
  if(argc==2){
    int theta=atoi(argv[1]);
    printf("theta: %d, sine(%d): %f\n", theta, theta, sineTable[(theta%360)]);
    printf("sineFunc(%d): %f\n", theta, sineFunc(theta));
  }
  return 0; 
}
