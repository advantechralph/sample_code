#ifndef __rand_h__
#define  __rand_h__
#include "basic.h"
#ifdef  __cplusplus
extern  "C" {
#endif 
float _genRand(void);
float _genRandFixed(int fixed);
float genRandFloat(float min, float max);
int genRandInt(int min, int max);
char *randString(char *str, size_t size);
char* randStringAlloc(size_t size);
#ifdef  __cplusplus
}
#endif 
#endif /*__rand_h__*/

