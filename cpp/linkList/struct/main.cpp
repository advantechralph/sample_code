#include <cstdio>
#include <iostream>
#include <vector>
using namespace std; 
#ifdef  __cplusplus
extern  "C" {
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef  __cplusplus
}
#endif 

struct node {
  int val; 
  node *next; 
  node():val(0),next(NULL){}
  node(int _v):val(_v),next(NULL){}
  node(int _v, node * _n):val(_v),next(_n){}
  void dump(void){
    for(node *p=this; p; p=p->next){
      cout << p->val;
      if(p->next) cout << " "; 
    }
  }
  void dump(const char *_n){ cout << _n << ": '"; dump(); cout << "'" << endl;}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  node *l1=new node(1, new node(2, new node(3)));
#if 0
  cout << l1->val << endl; 
#endif
  l1->dump(); cout << endl; 
  l1->dump("test");
  return 0; 
}

