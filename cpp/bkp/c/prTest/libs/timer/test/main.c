#include "timer.h"
static unsigned int timerCount=0; //max count: 4,294,967,295
void dumpTime(int s){
  timerCount++;
  if(timerCount%50==1){
    dumpNow();
  }
}
int main(void){
  printf("SIGRTMIN: %d, SIGRTMAX: %d\n", SIGRTMIN, SIGRTMAX);
  installRTHandler(SIGRTMIN, dumpTime);
  dumpTime(0);
  createRTTimer(SIGRTMIN, 0, 100000000);
  while(1){
    sleep(1);
  }
  return 0;
}
