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
  test.push_back(10);
  while(test.back()!=0){
    test.push_back(test.back()-1);
  }
  cout << "front: " << test.front() << endl;
  cout << "back: " << test.back() << endl;
  size_t count=0; 
  for(list<int>::iterator it=test.begin();it!=test.end();++it){ 
    if(it==test.begin()) cout << "test: '"; 
    cout << *it; 
    count++; 
    if(count==test.size()) cout << "'" << endl; 
    else cout << ",";
#if 0
    if(it!=(test.end()-1)) cout << "," ;
    else cout << "'" << endl;
#endif
  }
  return 0; 
}

