#ifndef __thread_h__
#define __thread_h__
#include "basic.h"
class Thread {
  pthread_t id;
  void *(*func)(void *);
  void *data;
  string name;
public:
  virtual void Init(const char *_n, void *(*_f)(void *), void *_d){
    name=string(_n?_n:"noname");
    func=_f;
    data=_d;
  }
  Thread(){
    printf("Thread(%p): '%s'@%d\n", this, __FILE__, __LINE__);
    Init(NULL, NULL, NULL);
  }
  Thread(const char *_n, void *(*_f)(void *), void *_d){
    printf("Thread(%p): '%s'@%d\n", this, __FILE__, __LINE__);
    Init(_n, _f, _d);
    Create();
  }
  ~Thread(){
    printf("~Thread(%p): '%s'@%d\n", this, __FILE__, __LINE__);
  }
  virtual void Create(void){
    pthread_create(&id, NULL, func, data);
  }
  virtual void Cancel(void){
    pthread_cancel(id);
  }
  virtual void Info(void){
  }
  virtual pthread_t Id(void){ return id; }
};
#endif /*__thread_h__*/
