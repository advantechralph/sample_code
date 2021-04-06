#include <iostream>
#include <vector>
#include "main.h"
using namespace std;
class Complex {
public:
  Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}
  Complex operator+(const Complex &); // use member function
  friend Complex operator*(Complex &, Complex &);
  friend ostream& operator<<(ostream &, const Complex &);
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
  cout << _c.re << "+" << _c.im << "i"; 
  return out; 
}
int main(void) {
  Complex c1(1,3);
  Complex c2(5,-2);
  Complex c3=c1*c2;
  cout << "c1=" << c1 << endl; 
  cout << "c2=" << c2 << endl; 
  cout << "c1*c2=" << (c1*c2) << endl; 
  return 0; 
}
