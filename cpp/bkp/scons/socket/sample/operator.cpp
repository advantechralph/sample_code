#include "main.h"
using namespace std; 
class Int {
public:
  Int(int _i=0):i(_i){
    for(int _n=0; _n<(int)(sizeof(arr)/sizeof(int)); _n++) arr[_n]=_n;
  }
  ~Int(){}
  Int& operator=(const int _i){
    cout << "operator = overloading..." << endl;
    this->i+=(_i*2);
    return *this;
  }
  Int& operator+=(const int _i){
    cout << "operator += overloading..." << endl;
    this->i+=(_i*3);
    return *this;
  }
  Int& operator[](int _s){
    cout << "operator []: " << endl; 
    return *(Int *)&arr[_s];
  }
  void dump(void){printf("value=%d\n", i);}
private:
 int i; 
 int arr[4];
};
void operatorTest(void){
  Int i1;
  Int i2(3);
  Int i3(4);
  i1.dump();
  i2.dump();
  i3.dump();
  i2=6;
  i2.dump();
  i3+=2;
  i3.dump();
  Int i4[]={(1),(2),(3),(4)};
  i4[2].dump();
  i4[2]=33; 
  i4[2].dump();
}
