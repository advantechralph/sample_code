#include "main.h"
#include "timer.h"
void test1Create300NodesTest(void){
  node *ph=NULL, *pcurr=NULL;
  int i=0, n=300; 
  unsigned long start=0, end=0; 
  start=getNow();
  dumpNow();
  for(i=0; i<n; i++){
    node *pn=NULL;
    pn=_createNewNodeWithRandKey();
    if(!pn) goto err;
//    printf("id: %d, key: %s\n", i, (char *)pn->key);
    if(!pcurr){
      pcurr=pn;
      ph=pcurr;
    }else{
      pcurr->next=pn; 
      pn->prev=pcurr; 
      pcurr=pn;
    }
  }
  end=getNow();
  printf("create 300 nodes time: %lu\n", end-start);
  i=0;
  // scan
  start=getNow();
  for(pcurr=ph; pcurr; pcurr=pcurr->next){
    //printf("id: %d, key: %s\n", i, (char *)pcurr->key);
    i++;
  }
  end=getNow();
  printf("scan time: %lu\n", end-start);
  return; 
err:
  printf("%s, %d: err\n", __FUNCTION__, __LINE__);
}
void test1AllocFreeTest(int n, int s){
  unsigned long start=0, end=0;
  int i=0; 
  start=getNow();
  for(i=0; i<n; i++){
    char *p=malloc(s); 
    randString(p, (s-1));
    if(p) free(p);
    else goto err;
  }
  end=getNow();
  printf("%s, %d: test: %d times done\n", __FUNCTION__, __LINE__, i);
  printf("alloc/free 10000/300 time: %lu\n", end-start);
  return; 
err:
  printf("%s, %d: err, test: %d times\n", __FUNCTION__, __LINE__, i);
}
void test1InstallHandler(int sig, void (*handler)(int s)){
  struct sigaction sa;
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = (void *)handler;
  sigemptyset(&sa.sa_mask);
  if(sigaction(sig, &sa, NULL) == -1)
      perror("sigaction");
}
timer_t test1CreateTimer(int sig, int sec){
  timer_t timerid;
  struct sigevent sev;
  struct itimerspec its;

  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = sig;
  sev.sigev_value.sival_ptr = &timerid;
  if(timer_create(CLOCK_REALTIME, &sev, &timerid) == -1)
      perror("timer_create");

  its.it_value.tv_sec = sec;
  its.it_value.tv_nsec = 0;
  its.it_interval.tv_sec = its.it_value.tv_sec;
  its.it_interval.tv_nsec = its.it_value.tv_nsec;

  if(timer_settime(timerid, 0, &its, NULL) == -1)
      perror("timer_settime");
  return timerid;
}
void dumpTime(int s){
  dumpNow();
}
#define freeNodesTestDebug
void freeNodesTest(node *ph){
  unsigned long start=0, end=0; 
  node *pcurr=NULL, *ptmp=NULL;;
  start=getNow();
  for(pcurr=ph, ptmp=pcurr; ptmp; ){
    if(pcurr){
#ifdef freeNodesTestDebug
      printf("pcurr: %p", pcurr);
#endif
      ptmp=pcurr->next;
      if(pcurr->key){
#ifdef freeNodesTestDebug
        printf(", has key!!");
#endif
        free(pcurr->key);
      }
      if(pcurr->data){ 
#ifdef freeNodesTestDebug
        printf(", has data!!");
#endif
        free(pcurr->data);
      }
#ifdef freeNodesTestDebug
      printf(", free done...\n");
#endif
      free(pcurr);
    }
    pcurr=ptmp;
  }
  end=getNow();
  printf("total free time: %lu(μs)\n", end-start);
  return; 
}
void test1CreateNodesTest(const int n, size_t s){
  node *ph=NULL, *pcurr=NULL;
  int i=0, ret=0; 
  unsigned long start=0, end=0; 
  start=getNow();
  for(i=0; i<n; i++){
    node *pn=NULL;
    pn=_createNewNodeWithRandKey();
    if(!pn){ ret=1; goto err; }
    pn->data=malloc(s);
    if(!pn->data){ ret=2; goto err; }
//    printf("id: %d, key: %s\n", i, (char *)pn->key);
    if(!pcurr){
      pcurr=pn;
      ph=pcurr;
    }else{
      pcurr->next=pn; 
      pn->prev=pcurr; 
      pcurr=pn;
    }
  }
  end=getNow();
  printf("create %d nodes time: %lu\n", n, end-start);
  // scan
  i=0;
  start=getNow();
  for(pcurr=ph; pcurr; pcurr=pcurr->next){
    printf("id: %d, key: %s, curr: %p, next: %p\n", i, (char *)pcurr->key, pcurr, pcurr->next);
    i++;
  }
  end=getNow();
  printf("scan time: %lu\n", end-start);
  printf("free %d nodes\n", n);
  freeNodesTest(ph);
  return; 
err:
  printf("%s, %d: err, ret: %d\n", __FUNCTION__, __LINE__, ret);
}
void test1(void){
  lib1_func1();
//  test1Create300NodesTest();
  printf("before test1CreateNodesTest\n");
  test1CreateNodesTest(5, 128);
  printf("after test1CreateNodesTest\n");
  test1AllocFreeTest(10000, 300);
  printf("SIGRTMIN: %d, SIGRTMAX: %d\n", SIGRTMIN, SIGRTMAX);
  test1InstallHandler(SIGRTMIN, dumpTime);
  test1CreateTimer(SIGRTMIN, 3);
  while(1){
    sleep(1);
  }
}

