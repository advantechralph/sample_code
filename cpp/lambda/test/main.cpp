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

int main(int argc, char *argv[]){
  //cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  int x = 10;
  //auto f = [&]() mutable -> void {
  auto f = [&]() {
      x = 20;
      cout << x << endl;
  };
  f();
  cout << x << endl; 
  return 0; 
}

