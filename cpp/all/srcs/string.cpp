#include <cstdio>
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

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

void erase(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  string str="xxxabcabc"; 
  string substr="abc"; 
  cout << str.find(substr) << endl;
  str.erase(str.find(substr), substr.length());
  cout << str << endl; 
  cout << "=========================================" << endl; 
}

funcTab testFuncTab[]={
  {erase}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

