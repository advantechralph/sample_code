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
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  int n1=2; 
  const int& n2=n1; 
  printf("%p, %p\n", &n1, &n2);
  n1=3; 
  cout << "n1: "  << n1 << endl; 
  cout << "n2: "  << n2 << endl; 
  //n2=4; error
  return 0; 
}

