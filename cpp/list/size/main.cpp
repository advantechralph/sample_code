#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
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
  list<int> test; 
  cout << test.size() << endl; 
  test.push_back(10);
  cout << test.size() << endl; 
  return 0; 
}

