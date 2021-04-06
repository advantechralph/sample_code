#include "basic.h"

void recursiveType1(const char*, int, int);

void recursiveType2(const char *na, const char *nb, int a, int b, int l){
  printf("%s, %d: layer: %d, %s: %d, %s: %d\n", __FUNCTION__, __LINE__, l, na, a, nb, b);
  fflush(stdout);
  usleep(500000);
  if(a>0) recursiveType1("a", a-1, l+1);
  if(b>0) recursiveType1("b", b-1, l+1);
}

void recursiveType1(const char *n, int s, int l){
  printf("%s, %d: layer: %d, %s: %d\n", __FUNCTION__, __LINE__, l, n, s);
  fflush(stdout);
  usleep(500000);
  if(s>0) recursiveType2("a", "b", s, s, l+1);
}

void test1(void){
  //recursiveType1("start", 5);
  recursiveType2("a", "b", 5, 4, 0);
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
