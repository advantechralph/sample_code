#ifndef __thread_h__
#define __thread_h__
#include "basic.h"
class Thread {
  pthread_t id; 
  static pthread_mutex_t mutex;
  static int init; 
public:
  void Init(void){
    if(init==0){
      pthread_mutex_init(&mutex, NULL);
      init=1;
    }
  }
  Thread(){}
  Thread(void *(*_Cb)(void*), void *_D){
    cout << "Thread(void *(*_Cb)(void*), void *_D)" << endl; 
    Init();
    pthread_create(&id, NULL, _Cb, _D);
  }
  ~Thread(){}
  void Info(void){
    cout << "Thread Info: " << endl; 
  }
  void Lock(void){
    pthread_mutex_lock(&mutex);
  }
  void Unlock(void){
    pthread_mutex_unlock(&mutex);
  }
}; 
int Thread::init=0; 
pthread_mutex_t Thread::mutex=PTHREAD_MUTEX_INITIALIZER;
#endif /*__thread_h__*/
