#include <iostream>
#include <cstdio>
#include "inherit.h"
using namespace std; 
int main(){
  cout << __FILE__ << "," 
    << __FUNCTION__ << "," 
    << __LINE__ << "\n";  
  SubClass sub1(1,2);
  sub1.test();
  return 0;
}
