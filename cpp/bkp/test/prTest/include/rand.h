#ifndef __rand_h__
#define __rand_h__
#include "basic.h"
static unsigned int _pwrTab[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
using namespace std;
class Rand {
  Timestamp ts;
public:
  Rand(){}
  ~Rand(){}
  void Srand(void){
    srand(ts.Now());
  }
  float Float(void){
    Srand();
    return (float)((float)rand()/(float)(RAND_MAX));
  }
  float Float(int fixed){
    float _f=Float();
    _f+=(float)((float)5/(float)(_pwrTab[fixed+1]));
    return (float)(((int)(_f*_pwrTab[fixed]))/(float)_pwrTab[fixed]);
  }
  float Float(float min, float max){
    float _f=Float();
    return ((float)(float)(_f*(max-min))+(float)min);
  }
  float Float(float min, float max, int fixed){
    float _f=Float(min, max);
    _f+=(float)((float)5/(float)(_pwrTab[fixed+1]));
    _f=(float)(((int)(_f*_pwrTab[fixed]))/(float)_pwrTab[fixed]);
    return _f; 
  }
  int Int(int min, int max){
    return (int)((Float((float)min, (float)(max+1))*10)/10); 
  }
}; 
#endif /*__rand_h__*/
