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
  string *s=new string("ooxx");
  cout << *s << endl; 
  printf("s: %p\n", (void *)s);
  cout << static_cast<void *>(s) << endl; 
  return 0; 
}

