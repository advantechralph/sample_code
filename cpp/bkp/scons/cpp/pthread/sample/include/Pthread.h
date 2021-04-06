#ifndef __Pthread_h__
#define __Pthread_h__
class Pthread {
public:
  Pthread(void); 
  void create(void *(*func)(void *),void *);
protected:
  pthread_t id; 
private:
};
Pthread::Pthread(void){
}
void Pthread::create(void *(*func)(void *), void *data){
  pthread_create(&id, NULL, func, data);
}
#endif /*__Pthread_h__*/
