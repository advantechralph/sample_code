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
  string s[]={
    "test", 
    "abcxyz", 
  }; 
  for(int i=0; i<(int)(sizeof(s)/sizeof(string)); i++){
    cout <<  "[" <<  i << "]: " << s[i] << endl; 
  }
  return 0; 
}

