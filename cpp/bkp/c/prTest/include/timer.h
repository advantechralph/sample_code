#ifndef __timer_h__
#define  __timer_h__
#include "basic.h"
#include "utils.h"
void installRTHandler(int sig, void (*handler)(int s));
timer_t createRTTimer(int sig, int sec, long nsec);
#endif /*__timer_h__*/

