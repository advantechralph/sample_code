#include <iostream>
#include "main.h"
using namespace std;
static Timestamp t; 
void t1func(int, siginfo_t*, void*){
  t.End();
  t.DumpDiff();
  printf("%s(): \n", __FUNCTION__);
}
int main(int argc, char *argv[]){
  cout << __FILE__ << ", " ; 
  cout << __FUNCTION__ << ", ";
  cout << __LINE__ << ": ";
  cout << endl; 
  t.Begin();
  Timer t1(SIGRTMIN, t1func, 1, 0); 
  while(1){sleep(1);}
  return 0; 
}
