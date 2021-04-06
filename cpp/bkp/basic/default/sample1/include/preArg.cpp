#include <iostream>
#include <cstdio>
#include "preArg.h"
using namespace std; 
double test(double=0.5, int=3, double=2.4); 
double test(double p1, int p2, double p3){
  double ans=p1*p2*p3;
  cout << p1 <<  "*" 
    << p2 << "*" 
    << p3 << "=" 
    << ans << "\n";
  return ans;
}
int main(){
  cout << __FILE__ << "," 
    << __FUNCTION__ << "," 
    << __LINE__ << "\n";  
  test(); 
  test(1); 
  test(2,1); 
  return 0;
}
