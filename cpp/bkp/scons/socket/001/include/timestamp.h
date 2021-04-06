#ifndef __timestamp_h__
#define  __timestamp_h__
#include "basic.h"
#ifdef  __cplusplus
extern  "C" {
#endif 
unsigned long getNow(void);
void dumpNow(void);
void dumpNowSec(void);
void dumpNowUSec(void);
const char *getNowStr(void);
#ifdef  __cplusplus
}
#endif 
#endif /*__timestamp_h__*/

