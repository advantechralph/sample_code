#ifndef __Task_h__
#define __Task_h__
class Task {
public:
  Task(void);
  void init(void);
  void installHandler(int , void (*)(int, siginfo_t*, void*));
  timer_t createTimer(int, int, long);
  void triggerTimer(void);
protected:
  static void rtTimer(int, siginfo_t*, void*); 
  void *rtTimerPtr(void);
  int rtTimer_sec; 
  int rtTimer_nsec; 
  Pthread *sampleChild;
  static void *sampleChildHdl(void *data);
  static sem_t sampleChildSem; 
private:
};
sem_t Task::sampleChildSem; 
Task::Task(void){
  sampleChild=new Pthread();
  rtTimer_sec=0;
  rtTimer_nsec=500*1000*1000; 
  sem_init(&sampleChildSem, 0, 0);
}
void Task::init(void){
  sampleChild->create(sampleChildHdl,(void *)"sampleChildHdl");
  triggerTimer();
}
void *Task::sampleChildHdl(void *data){
  char *str=(char *)data; 
  while(1){
    printf("%s wait...\n", str);
    sem_wait(&sampleChildSem);
    printf("%s...\n", str);
  }
  pthread_exit(NULL);
}
void Task::installHandler(int sig, void (*handler)(int, siginfo_t*, void*)){
  struct sigaction sa;
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = handler;
  sigemptyset(&sa.sa_mask);
  if(sigaction(sig, &sa, NULL) == -1)
    perror("sigaction");
}
timer_t Task::createTimer(int sig, int sec, long nsec){
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
void Task::rtTimer(int, siginfo_t*, void*){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  sem_post(&sampleChildSem);
}
void *Task::rtTimerPtr(void){
  return (void *)rtTimer; 
}
void Task::triggerTimer(void){
  installHandler(SIGRTMIN, rtTimer);
  createTimer(SIGRTMIN, rtTimer_sec, rtTimer_nsec); //1 sec
}
#endif /*__Task_h__*/
