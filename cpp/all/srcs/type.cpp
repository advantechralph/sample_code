#include <cstdio>
#include <iostream>
#include <vector>
#include <typeinfo>
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

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

template <typename T> const char* typeof(T&) { return "unknown"; }    // default
template<> const char* typeof(int&) { return "int"; }
template<> const char* typeof(const int&) { return "const int"; }
template<> const char* typeof(float&) { return "float"; }
template<typename T> const char* constof(T&) { return "not const"; }
template<typename T> const char* constof(const T&) { return "const"; }

void decltypeTest(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  const int a=100; 
  decltype(a) b=200; 
  int c=300; 
  cout << "a, b: " << a << ", " << b << endl; 
  cout << "typeid(decltype(a)).name(): " << typeid(decltype(a)).name() << endl; 
  cout << "typeid(a).name(): " << typeid(a).name() << endl; 
  cout << "typeof(a): " << typeof(a) << endl; 
  cout << "constof(a): " << constof(a) << endl; 
  cout << "constof(b): " << constof(b) << endl; 
  cout << "constof(c): " << constof(c) << endl; 
  cout << "=========================================" << endl; 
}

funcTab testFuncTab[]={
  {decltypeTest}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

