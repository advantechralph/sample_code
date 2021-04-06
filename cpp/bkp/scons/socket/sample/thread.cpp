#include "main.h"
class thread {
public: 
  void init(const char *_n, void *(*_f)(void *), void *_d){
    char _buf[32]={0};
    name=string(_n?_n:"noname");
    func=_f;
    data=_d;
    if(_f) sprintf(_buf, "(%p)", _f);
    else sprintf(_buf, "(0)");
    name+=_buf; 
  }
  void init(void *(*_f)(void *), void *_d){init(NULL, _f, _d);}
  thread(const char *_n=NULL, 
         void *(*_f)(void *)=NULL, 
	 void *_d=NULL){
    init(_n, _f, _d);
  }
  thread(void *(*_f)(void *), void *_d){
    init(NULL, _f, _d);
  }
  ~thread(){}
  void create(void){
    if(func){
      pthread_create(&id, NULL, func, data);
    }
  }
  void info(void){
    cout << "thread info: " << endl; 
    cout << "  " << name << endl; 
    cout << "  " << "func("<< static_cast<void *>((void *)func) <<")" << endl; 
    cout << "  " << "data("<< static_cast<void *>((void *)data) <<")" << endl; 
  }
private:
  pthread_t id; 
  void *(*func)(void *);
  void *data;
  string name;
};
void *t1func(void *data){
  while(1){
    printf("%s: \n", (char *)data);
    sleep(1);
  }
}
void *t2func(void *data){
  while(1){
    printf("%s: \n", (char *)data);
    sleep(1);
  }
}
void *t3func(void *data){
  while(1){
    printf("%s: \n", (char *)data);
    sleep(1);
  }
}
void threadTest(void){
  thread t1;
  thread t2("t2", t2func, (void *)"t2");
  thread t3(t3func, (void *)"t3");
  t1.init(t1func, (void *)"t1");
  t1.info();
  t2.info();
  t3.info();
  usleep(100);
  t1.create();
  t2.create();
  t3.create();
}
