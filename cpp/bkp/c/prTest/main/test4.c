#include "main.h"
#include "timer.h"
static sem_t test4Sem1; 
static sem_t test4Sem2; 
static pthread_t test4Child1_t; 
static pthread_t test4Child2_t; 
//teset insert nodes...
void *test4Child1Func(void* data) {
  char *str=(char*)data; 
  unsigned int loopCount=0; 
  unsigned long now=0; 
  while(1){
    int sem_count=0; 
    sem_wait(&test4Sem1);
    sem_getvalue(&test4Sem1, &sem_count);
    if(sem_count>1){
      printf("WARNING: %s sem_count > 1 !!\n", str);
    }
    if((loopCount%100)==0){
      now=getNow();
      printf("%s: timestamp: %lu\n", str, now);
    }
    loopCount++;
  }
  pthread_exit(NULL); 
}
void *test4Child2Func(void* data) {
  char *str=(char*)data; 
  unsigned int loopCount=0; 
  unsigned long now=0; 
  while(1){
    int sem_count=0; 
    sem_wait(&test4Sem2);
    sem_getvalue(&test4Sem2, &sem_count);
    if(sem_count>1){
      printf("WARNING: %s sem_count > 1 !!\n", str);
    }
    if((loopCount%100)==0){
      now=getNow();
      printf("%s: timestamp: %lu\n", str, now);
    }
    loopCount++;
  }
  pthread_exit(NULL); 
}
void test4Timer(int s){
  sem_post(&test4Sem1);
  sem_post(&test4Sem2);
}
void test4(void){
  sem_init(&test4Sem1, 0, 0);
  sem_init(&test4Sem2, 0, 0);
  pthread_create(&test4Child1_t, NULL, test4Child1Func, "test4Child1Func"); 
  pthread_create(&test4Child2_t, NULL, test4Child2Func, "test4Child2Func"); 
  installRTHandler(SIGRTMIN, test4Timer);
  createRTTimer(SIGRTMIN, 0, 100*1000*1000);
  while(1){
    sleep(1);
  }
}

