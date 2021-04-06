#include "basic.h"

typedef list<int> List; 

void dumpList(List *pi){
  cout << "list: { "; 
#if 0
  List::iterator before_end=pi->end();
  advance(before_end, -1);
  for(List::iterator it=pi->begin(); it!=pi->end(); it++){
    cout << *it; 
    if(before_end==it) break;
    else cout << ", ";
  }
#else
  for(List::iterator it=pi->begin();it!=pi->end();){
    cout << *it++; 
    if(it==pi->end()) break; 
    else cout << ", ";
  }
#endif
  cout << " }" << endl; 
}

void eraseList(List *pi){
  for(List::iterator it=pi->begin(); it!=pi->end(); ){
    pi->erase(it++);
  }
}

void eraseTest1(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  List i={100,50,30,40,200,250,60};
  cout << "i.szie(): " << i.size() << endl; 
  cout << "i.erase(i.begin());" << endl; 
  i.erase(i.begin()); 
  //cout << i.size() << endl; 
  dumpList(&i);
  for(List::iterator it=i.begin();it!=i.end(); ){
    cout << *it++ << endl; 
  }
  eraseList(&i);
  dumpList(&i);
  cout << "=========================================" << endl; 
}

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

funcTab testFuncTab[]={
  {eraseTest1}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}
