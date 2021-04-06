#include <iostream>
#include <cstdio>
using namespace std;
class father {
  int id; 
public:
  void init(int p1, int p2){
    printf("%s, %d: p1: %d, p2: %d\n", __FUNCTION__, __LINE__, p1, p2);
  }
  father(int p1=0, int p2=0){
    init(p1,p2);
  }
  ~father(){}
  virtual void info(void){
    printf("%s, %d: father\n", __FUNCTION__, __LINE__);
  }
};
class son:public father {
public:
  son(int p1=0, int p2=0){
    init(1,2);
  }
  ~son(){}
  virtual void info(void){
    printf("%s, %d: son\n", __FUNCTION__, __LINE__);
  }
};
class grandson:public son {
public: 
  grandson(){}
  ~grandson(){}
  virtual void info(void) override {
    printf("%s, %d: grandson\n", __FUNCTION__, __LINE__);
  }
}; 
int main(void){
  son s1;
  grandson gs1;
  s1.info();
  gs1.info();
  int y=3; 
  auto f=[&y](int x) -> bool {return ((x+(y--))>10); };
  cout << "y:" << y << endl;
  cout << f(6) << endl; 
  cout << "y:" << y << endl;
  cout << f(10) << endl; 
  cout << "y:" << y << endl;
  cout << f(10) << endl; 
  cout << "y:" << y << endl;
  cout << f(10) << endl; 
  cout << "y:" << y << endl;
  return 0; 
}
