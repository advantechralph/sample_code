#include <iostream>
#include "main.h"
class Parent {
public:
  Parent(){
    FUNC
  }
  ~Parent(){
    FUNC
  }
  virtual void Info(void){
    cout << "Parent::" << __FUNCTION__ << "()" << endl; 
  }
};
class Child:public Parent {
public:
  Child(){
    FUNC
  }
  ~Child(){
    FUNC
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
