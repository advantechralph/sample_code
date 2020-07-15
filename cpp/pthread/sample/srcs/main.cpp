#include "main.h"
typedef void *(*tCb)(void*);
class Thread {
  string name;
  static int static_val; 
  pthread_t id;
  static pthread_mutex_t lock;
  tCb Cb; 
  void *D; 
public:
  Thread():name(string("noname")){}
  ~Thread(){}
  Thread(const char *_name){
    name=string(_name);
  }
  Thread(const char *_name, tCb _Cb){
    name=string(_name);
    Cb=_Cb;
    D=(void *)this; 
    Run();
  }
  void Info(void){
    cout << name << "." << __FUNCTION__ << "():";
    cout << " static_val(" << static_val << ")";
    cout << endl;
  }
  void Assign(int _v){
    static_val=_v;
    cout << name << "." << __FUNCTION__ << "(" << _v << ")" << endl;
  }
  void Register(tCb _Cb){
    Cb=_Cb; 
  }
  void Run(void){
    pthread_create(&id, NULL, Cb, (void *)this);
  }
  void Lock(void){
    pthread_mutex_lock(&lock);
  }
  void Unlock(void){
    pthread_mutex_unlock(&lock);
  }
};
int Thread::static_val=2; 
pthread_mutex_t Thread::lock; 
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
int main(int argc, char *argv[]){
  Thread p1("p1", (tCb)Cb1); 
  Thread p2("p2", (tCb)Cb2); 
  Thread p3; 
  p3.Register((tCb)Cb2);
  p3.Run();
  while(1){
    sleep(1);
  }
  return 0; 
}
