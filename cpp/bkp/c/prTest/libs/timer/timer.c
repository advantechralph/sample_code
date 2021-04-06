#include "timer.h"
void installRTHandler(int sig, void (*handler)(int s)){
  struct sigaction sa;
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = (void *)handler;
  sigemptyset(&sa.sa_mask);
  if(sigaction(sig, &sa, NULL) == -1)
      perror("sigaction");
}
timer_t createRTTimer(int sig, int sec, long nsec){
  timer_t timerid;
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
  return timerid;
}
