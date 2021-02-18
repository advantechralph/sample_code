#include <iostream>
#include <vector>

using namespace std;

#ifdef  __cplusplus
extern  "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef  __cplusplus
}
#endif

class sample {
  int a; 
  void init(void); 
public: 
  sample(){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    init();
  }
  ~sample(){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
  void set(int _a){
    a=_a; 
  }
  void dump(void){
    printf("%s, %d: a: %d\n", __FUNCTION__, __LINE__, a);
  }
}; 

void test1(void){
  printf("%s, %d: start\n", __FUNCTION__, __LINE__);
  sample *p=new sample();
  p->dump();
  p->set(5);
  p->dump();
  delete p; 
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}

template <typename T> 
T testTemplateFunc1(T t1, T t2){
  return (t1 + t2); 
}

void test2(void){
  printf("%s, %d: start\n", __FUNCTION__, __LINE__);
  int a=5, b=8, c=0; 
  c=testTemplateFunc1(a, b);
  cout << "c: " << c << endl; 
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}

int main(void){
  test2();
  return 0; 
}

void sample::init(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  this->a=0; 
}

