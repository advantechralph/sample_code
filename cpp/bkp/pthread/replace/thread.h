#ifndef __thread_h__
#define __thread_h__
#include "main.h"
typedef void *(*tCb)(void*);
class Thread {
  string name;
  static int static_val; 
  pthread_t id;
  static pthread_mutex_t mutex;
  tCb Cb; 
  void *D; 
  static int init; 
public:
  Thread(){
    Init();
  }
  Thread(const char *_name){
    Init();
    name=string(_name);
  }
  Thread(const char *_name, tCb _Cb){
    Init();
    name=string(_name);
    Cb=_Cb;
    Run();
  }
  Thread(const char *_name, tCb _Cb, void *_D){
    Init();
    name=string(_name);
    Cb=_Cb;
    D=_D; 
    Run();
  }
  ~Thread(){}
  void Init(void){
    if(!init){
      name=string("noname");
      pthread_mutex_init(&mutex, NULL);
      D=NULL;
      init=1; 
    }
  }
  const char *Name(void){
    return name.c_str(); 
  }
  virtual void Info(void){
    cout << Name() << "." << __FUNCTION__ << "():";
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
    pthread_mutex_lock(&mutex);
  }
  void Unlock(void){
    pthread_mutex_unlock(&mutex);
  }
};
int Thread::static_val=2; 
int Thread::init=0; 
pthread_mutex_t Thread::mutex=PTHREAD_MUTEX_INITIALIZER; 
#endif /*__thread_h__*/
