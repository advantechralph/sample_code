#include <iostream>
#include <cstdio>
#include <string>
#include "operatorOverloading.h"
using namespace std; 
double testClass::func1(double p1,int p2){
  double ans=p1*p2;
  cout << p1 << "*" << p2 << "=" << ans << "\n" ;
  return ans;
}
testClass& testClass:: operator++(const int a){
  this->param1++;
  return *this;
}
testClass& testClass:: operator--(const int a){
  this->param1--;
  return *this;
}
testClass& testClass:: operator+=(string& s){
  this->param3=s;
  return *this; 
}
testClass& testClass:: operator+=(const string& s){
  this->param3=s;
  return *this; 
}
void testClass::dump(){
  printf("######## DUMP #######\n");
  cout << "param1: " << param1 << "\n"; 
  cout << "param2: " << param2 << "\n"; 
  cout << "param3: " << param3 << "\n"; 
  printf("######## END ########\n");
}
#if 0
testClass::testClass(){
  printf("%s, %d\n", __FUNCTION__, __LINE__);
}
#endif
class Int {
  public:
    Int(){ 
      printf("%s, %d: \n", __FUNCTION__, __LINE__);
      _v=0; 
    }
    Int(int v){ 
      printf("%s, %d: \n", __FUNCTION__, __LINE__);
      _v=v; 
    }
    ~Int(){ 
      printf("%s, %d: \n", __FUNCTION__, __LINE__);
    }
    void dump(void){
      printf("%s, %d: _v=%d\n", __FUNCTION__, __LINE__, _v);
    }
  private:
    int _v;
};
void test1(void){
  testClass t1;
  string n("test");
  printf("before t1.func1()\n");
  t1.func1();
  cout << __FILE__ << "," 
    << __FUNCTION__ << "," 
    << __LINE__ << "\n";  
  t1.dump();
  string s("before ++");
  t1+=s;
  t1++;
  t1.dump();
  s=string("before --");
  //t1+=s;
  t1+=string("before --");
  t1--;
  t1.dump();
}
void test2(void){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Int i1;
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Int i2();
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Int i3(5);
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Int i4=i1;
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  Int *i5=new Int();
  i4.dump();
  i5->dump();
  //delete i5;
}
int main(){
  test1();
  test2();
  return 0;
}
