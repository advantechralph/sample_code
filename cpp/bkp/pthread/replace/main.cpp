#include "main.h"
#include "thread.h"
tCb Cb1(void *D){
  pthread_detach(pthread_self());
  Thread *pD=(Thread *)D; 
  while(1){
    pD->Lock();
    pD->Info();
    pD->Assign(11);
    pD->Info();
    pD->Unlock();
    usleep(100000);
  }
  pthread_exit(NULL);
}
tCb Cb2(void *D){
  pthread_detach(pthread_self());
  Thread *pD=(Thread *)D; 
  while(1){
    pD->Lock();
    pD->Info();
    pD->Assign(22);
    pD->Info();
    pD->Unlock();
    sleep(1);
  }
  pthread_exit(NULL);
}
class TestThread:public Thread {
public:
  virtual void Info(void){
    cout << Name() << "." << __FUNCTION__ << "():";
    cout << " Info(replace)";
    cout << endl;
  }
}; 
tCb TestCb(void *D){
  pthread_detach(pthread_self());
  Thread *pD=(Thread *)D; 
  while(1){
    pD->Lock();
    pD->Info();
    pD->Unlock();
    sleep(1);
  }
  pthread_exit(NULL);
}
int main(int argc, char *argv[]){
#if 0
  Thread p1("p1", (tCb)Cb1); 
  Thread p2("p2", (tCb)Cb2); 
  Thread p3; 
  p3.Register((tCb)Cb2);
  p3.Run();
#else
  TestThread t; 
  t.Register((tCb)TestCb);
  t.Run();
#endif
  while(1){
    sleep(1);
  }
  return 0; 
}
