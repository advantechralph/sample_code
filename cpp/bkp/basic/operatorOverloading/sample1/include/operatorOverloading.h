#ifndef __operatorOverloading_h__
#define __operatorOverloading_h__
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class testClass {
  public:
    testClass(){
      param1=0;
      param2=0;
      param3="init!!";
    }
    double func1(double=0.2,int=3);
    testClass& operator++(const int); 
    testClass& operator--(const int); 
    testClass& operator+=(string&); 
    testClass& operator+=(const string&); 
    void dump();
  private:
    double param1;
    int param2;
    string param3;
};
#endif
