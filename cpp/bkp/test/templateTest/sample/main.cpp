#include <iostream>
#include "main.h"
using namespace std;
template <typename T1> 
class _testClass {
  T1 p1;
public: 
  _testClass():p1(555){}
  ~_testClass(){}
  T1& getP1(int _c){return p1;}
  void Dump(void){cout << p1 << endl;}
};
typedef class _testClass<int> testClass;
int main(int argc, char *argv[]){
  testClass t;
  int c=t.getP1(33);
  cout << c << endl;
  c=55;
  t.Dump();
  return 0; 
}

