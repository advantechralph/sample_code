#ifndef __timer_h__
#define __timer_h__
#include "basic.h"
class Timer {
  int sig; 
  timer_t timerid;
  void (*func)(int, siginfo_t*, void*);
  int sec; 
  long nsec;
public:
  void Init(int _sig, void (*_func)(int, siginfo_t*, void*), int _sec, long _nsec){
    sig=_sig;
    func=_func;
    sec=_sec;
    nsec=_nsec;
  }
  Timer(){
    printf("Timer(%p): '%s'@%d\n", this, __FILENAME__, __LINE__);
    Init(-1, NULL, -1, -1);
  }
  Timer(int _sig, void (*_func)(int, siginfo_t*, void*), int _sec, long _nsec){
    printf("Timer(%p): '%s'@%d\n", this, __FILENAME__, __LINE__);
    Init(_sig, _func, _sec, _nsec);
    Install();
    Run();
  }
  Timer(void (*_func)(int, siginfo_t*, void*), int _sec, long _nsec){
    printf("Timer(%p): '%s'@%d\n", this, __FILENAME__, __LINE__);
  }
  ~Timer(){
    printf("~Timer(%p): '%s'@%d\n", this, __FILENAME__, __LINE__);
  }
  void Install(void){
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = func;
    sigemptyset(&sa.sa_mask);
    if(sigaction(sig, &sa, NULL) == -1)
      perror("sigaction");
  }
  void Run(void){
    struct sigevent sev;
    struct itimerspec its;
  
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = sig;
    sev.sigev_value.sival_ptr = &timerid;
    if(timer_create(CLOCK_REALTIME, &sev, &timerid) == -1)
      perror("timer_create");
  
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = nsec;
    its.it_interval.tv_sec = its.it_value.tv_sec;
    its.it_interval.tv_nsec = its.it_value.tv_nsec;
  
    if(timer_settime(timerid, 0, &its, NULL) == -1)
      perror("timer_settime");
  }
};
#endif /*__timer_h__*/
