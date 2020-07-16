#include <iostream>
#include <vector>
#include "main.h"
#define FUNC cout << __FUNCTION__ << "()" << endl;
#ifdef  __cplusplus
extern  "C" {
#endif 
#include <stdio.h>
#ifdef  __cplusplus
}
#endif 
class S {
  int value; 
public: 
  S(){
    throw "test!!"; 
  }
  S(int _v):value(_v){}; 
  friend ostream& operator<<(ostream& out, const S& _s);
  ~S(){
  }
};
ostream& operator<<(ostream& out, const S& _s){
  return (out<<_s.value); 
}
int main(void){
  try {
    S s1; 
  }
  catch(const char *e){
    cout << e << endl; 
  }
  return 0; 
}

