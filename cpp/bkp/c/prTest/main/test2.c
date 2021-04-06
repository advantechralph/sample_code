#include "main.h"
#include "timer.h"
static unsigned int test2TimerCount=0;
static unsigned int test2TimerMod=10; //100*100 ms dump
static long test2TimerNSec=500*1000*1000; //100ms
void test2Timer(int s){
#if 1
  if((test2TimerCount%test2TimerMod)==1){
    dumpNow();
  }
  test2TimerCount++; 
#else
  dumpNow();
#endif
}
void test2(void){
  installRTHandler(SIGRTMIN, test2Timer);
  dumpNow();
  createRTTimer(SIGRTMIN, 0, test2TimerNSec);
  while(1){
    sleep(1);
  }
}
