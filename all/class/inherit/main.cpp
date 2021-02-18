#include <iostream>
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
class father {
  int a; 
  int b; 
  void init(void); 
public: 
  father():b(3){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    init();
  }
  father(int _b){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    init();
    b=_b; 
  }
  ~father(){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
  void set(int _a){
    a=_a; 
  }
  void dump(void){
    printf("%s, %d: a: %d, b: %d\n", __FUNCTION__, __LINE__, a, b);
  }
}; 
class son1:public father {
public: 
  son1(){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
  ~son1(){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
}; 
class son2:public father {
public: 
  son2():father(-1){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
  son2(int _b):father(_b){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
  ~son2(){
    printf("%s, %d\n", __FUNCTION__, __LINE__);
  }
}; 
void testcase1(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  father *p=new father();
  p->dump();
  p->set(5);
  p->dump();
  delete p; 
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}
void testcase2(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  class son1 *p=new son1();
  p->dump();
  delete p; 
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}
void testcase3(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  class son2 *p=new son2();
  p->dump();
  delete p; 
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}
void testcase4(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  class son2 *p=new son2(99);
  p->dump();
  delete p; 
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}
int main(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  testcase1();
  testcase2();
  testcase3();
  testcase4();
  return 0; 
}
void father::init(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  this->a=0; 
}
