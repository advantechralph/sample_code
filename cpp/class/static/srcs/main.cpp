#include "main.h"

class Sample {
  string name; 
  static int static_val; 
public: 
  Sample(){
    printf("%s, %d: \n", __FUNCTION__, __LINE__);
    name=string("noname");
  }
  ~Sample(){}
  Sample(const char *_name){
    printf("%s, %d: \n", __FUNCTION__, __LINE__);
    name=string(_name); 
  }
  void Info(void);
  void Assign(int _val); 
}; 
void Sample::Info(void){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  cout << name << "." << __FUNCTION__ << "(): ";
  cout << "static_val=" << static_val; 
  cout << endl ; 
}
void Sample::Assign(int _val){
  static_val=_val; 
}
int Sample::static_val=1;
int main(int argc, char *argv[]){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Sample s1;
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Sample s2("s2");
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  s1.Assign(5);
  s1.Info();
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  s2.Info();
  return 0; 
}
