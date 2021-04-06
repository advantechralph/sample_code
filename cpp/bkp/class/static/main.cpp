#include <iostream>
#include "main.h"
class Sample {
  string name;
  static int static_val; 
public:
  Sample(){}
  ~Sample(){}
  Sample(const char *_name){
    name=string(_name);
  }
  void Info(void){
    cout << name << "." << __FUNCTION__ << "():";
    cout << " static_val(" << static_val << ")";
    cout << endl;
  }
  void Assign(int _v){
    static_val=_v;
    cout << name << "." << __FUNCTION__ << "(" << _v << ")" << endl;
  }
};
int Sample::static_val=2; 
int main(int argc, char *argv[]){
  Sample s1("s1"); 
  Sample s2("s2"); 
  s1.Info();
  s2.Info();
  s1.Assign(33);
  s2.Info();
  s2.Assign(44);
  s2.Info();
  s1.Info();
  return 0; 
}
