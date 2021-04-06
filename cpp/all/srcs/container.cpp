#include "basic.h"

class Data{
  int val; 
//  const char* data; 
  string data;
public: 
  Data(){}
  Data(int v):val(v), data("default data"){}
  Data(int v, const char* s):val(v),data(s){}
  ~Data(){}
  void info(void){ cout << "val: " << val << ", data: " << data << endl; }
  void set(string s){ this->data=s; }
}; 
typedef map<const char *, Data> Map; 
void mapTest(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  Map m; 
  Map m2={
    {"k1", Data(1)},
    {"k2", Data(2, "k2 data")},
    {"k3", Data(2, "k3 data")}
  }; 
  m["key1"]=Data(2); 
  m["key2"]=Data(1, "key2 data"); 
  m["key1"].info();
  m2["k3"].set("ooxx");
  m2["k3"].info();
  cout << "=========================================" << endl; 
}

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

funcTab testFuncTab[]={
  {mapTest}, 
  {NULL}
}; 

map<const char *, void (*)(void)> testKeyFuncTab;

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}

