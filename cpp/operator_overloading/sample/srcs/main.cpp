#include "main.h"

class Sample {
  int a; 
  int b; 
public: 
  Sample(){
    //printf("%s(%p)\n", __FUNCTION__, this);
    cout << __FUNCTION__ << "(" << this << ")" << endl;
    a=1; b=2;
  }
  Sample(int _a, int _b){
    printf("%s(%p)\n", __FUNCTION__, this);
    a=_a; 
    b=_b; 
  }
  ~Sample(){
    printf("%s(%p)\n", __FUNCTION__, this);
  }
  void info(void){
    cout << "a: " << a << ", b: " << b << endl; 
  }
  Sample operator+(const Sample &_in){
    Sample _out; 
    _out.a=this->a+_in.a; 
    _out.b=this->b+_in.b; 
    return _out;
  }
  Sample operator*(const Sample &_in){
    Sample _out; 
    _out.a=this->a*_in.a; 
    _out.b=this->b*_in.b; 
    return _out;
  }
  friend ostream& operator<<(ostream &out, const Sample &_in);
}; 
ostream& operator<<(ostream &out, const Sample &_in){
  cout << "a: " << _in.a << ", b: " << _in.b; 
  return out; 
}
int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << ": " << endl;
  Sample s1, s2(2,3); 
  s1.info();
  s2.info();
  Sample s3; 
  s3=s1+s2;
  s3.info();
  Sample s4; 
  s4=s1*s2;
  s4.info();
  cout << "s4: " << s4 << endl; 
  return 0; 
}
