#include "basic.h"

void test1(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  cout << "=========================================" << endl; 
}

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

funcTab testFuncTab[]={
  {test1}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}
