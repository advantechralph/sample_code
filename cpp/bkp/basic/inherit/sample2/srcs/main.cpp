#include <iostream>
#include <cstdio>
#include "class.h"
using namespace std; 
int main(){
  Ball ball1;
  cout << __FILE__ << "," 
    << __FUNCTION__ << "," 
    << __LINE__ << "\n";  
  cout << ball1.name() << "\t"
       << ball1.volumn() 
       << endl;

  ball1.name("green ball");
  ball1.radius(2.5);
  cout << ball1.name() << "\t"
       << ball1.volumn() 
       << endl;

  Ball ball2(5.0, "black ball");
  cout << ball2.name() << "\t"
       << ball2.volumn() 
       << endl; 

  string name("yellow ball");
  Ball ball3(10.0, name);

  cout << ball3.name() << "\t"
       << ball3.volumn() 
       << endl;

  football football1(3.3, "football 1");
  cout << football1.name() << "\t"
       << football1.volumn() 
       << endl;

  return 0;
}
