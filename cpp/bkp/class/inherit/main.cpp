#include <iostream>
#include "main.h"
class Parent {
public:
  Parent(){
    cout << __FUNCTION__ << "()" << endl;
  }
  ~Parent(){
    cout << __FUNCTION__ << "()" << endl;
  }
  virtual void Info(void){
    cout << "Parent::" << __FUNCTION__ << "()" << endl; 
  }
};
class Child:public Parent {
public:
  Child(){
    cout << __FUNCTION__ << "()" << endl;
  }
  ~Child(){
    cout << __FUNCTION__ << "()" << endl;
  }
  virtual void Info(void){
    cout << "Child::" << __FUNCTION__ << "()" << endl; 
  }
};
int main(int argc, char *argv[]){
  Parent p; 
  Child c; 
  p.Info();
  c.Info();
  return 0; 
}
