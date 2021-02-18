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

template <typename T>
class sample {
  T a; 
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
    cout << __FUNCTION__ << ", " << __LINE__ << ": a: "  << a << endl; 
  }
}; 

void test1(void){
  printf("%s, %d: start\n", __FUNCTION__, __LINE__);
  sample<int> s1; 
  s1.dump();
  printf("%s, %d: end\n", __FUNCTION__, __LINE__);
}

int main(void){
  test1();
  return 0; 
}

template <class T>
void sample<T>::init(void){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
  this->a=0; 
}

