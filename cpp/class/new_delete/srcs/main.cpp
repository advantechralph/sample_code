#include "main.h"

class Sample {
public: 
  Sample(){
    printf("%s(%p)\n", __FUNCTION__, this);
  }
  ~Sample(){
    printf("%s(%p)\n", __FUNCTION__, this);
  }
}; 
int main(int argc, char *argv[]){
  cout << "*pS=new Sample();" << endl;
  Sample *pS=new Sample(); 
  cout << "pS=" << pS << endl;
  Sample S=Sample();
  cout << "delete pS;" << endl;
  delete pS; 
  return 0; 
}
