#include <iostream>
using namespace std; 
class Sample {
  int x; 
public: 
  Sample(): x(1){
  }
  Sample(const int _x){
    x=_x; 
  }
  ~Sample(){
  }
  void info(void){
    cout << "x: " << x << endl; 
  }
}; 

int main(void){
  Sample s1; 
  s1.info();
  return 0; 
}

