#include <iostream>
#include <vector>
#include "main.h"
using namespace std;
class Complex {
public:
  Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {
    //cout << "Complex(" <<  this << ")" << endl; 
    printf("Complex(%p)\n", this);
  }
  ~Complex(){
    //cout << "~Complex(" <<  this << ")" << endl; 
    printf("~Complex(%p)\n", this);
  }
  Complex operator+(const Complex &); // use member function
  friend Complex operator*(Complex &, Complex &);
  friend ostream& operator<<(ostream &, const Complex &);
  void dump(void){ cout << this << endl; }
private:
  double re;
  double im;
};
Complex Complex::operator+(const Complex &_c){
  Complex _sum;
  _sum.re=this->re+_c.re;
  _sum.im=this->im+_c.im;
  return _sum;
}
Complex operator*(Complex &_c1, Complex &_c2){
  Complex _mul;
  _mul.re=_c1.re*_c2.re-_c1.im*_c2.im;
  _mul.im=_c1.re*_c2.im+_c1.im*_c2.re;
  return _mul;
}
ostream& operator<<(ostream &out, const Complex &_c){
  if(_c.im<0){
    cout << _c.re << _c.im << "i"; 
  }else{
    cout << _c.re << "+" << _c.im << "i"; 
  }
  return out; 
}
int main(void) {
  cout << "before vector..." <<endl; 
  vector <Complex> c;
  cout << "push_back..." <<endl; 
  c.push_back(*(new Complex(-1,3)));
  cout << "push_back..." <<endl; 
  c.push_back(*(new Complex(4,-5)));
  cout << "c[0]=" << c[0] << endl;
  cout << "c[1]=" << c[1] << endl;
  cout << "c[0]*c[1]=" << c[0]*c[1] << endl;
  c.clear();
  c.assign(3,*(new Complex(0,0)));
  cout << "c[0]=" << c[0] << endl;
  cout << "c[1]=" << c[1] << endl;
  cout << "c[0]*c[1]=" << c[0]*c[1] << endl;
  cout << "c.size()=" << c.size() << endl;
  c.clear();
  Complex ctmp;
  ctmp=Complex(1,3);
  ctmp=Complex(-1,-3);
  return 0; 
}
