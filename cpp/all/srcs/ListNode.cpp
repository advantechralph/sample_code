#include "basic.h"

struct ListNode {
  int val; 
  ListNode *prev; 
  ListNode *next; 
  ListNode(void):val(0), prev(NULL), next(NULL){};
  ListNode(int v):val(v), prev(NULL), next(NULL){};
  ListNode(int v, ListNode *n):val(v), next(n){ if(n) n->prev=this; };
  ListNode(int v, ListNode *p, ListNode *n):val(v), prev(p), next(n){ if(n) n->prev=this; };
  void dump(void){cout << "this: " << this << ", val: " << val << endl; }
  void dumpAll(void){ for(ListNode *p=this; p; p=p->next){ p->dump(); } }
  ListNode *begin(void){ for(ListNode *p=this; p; p=p->prev){ if(p->prev==NULL) return p; } }
  ListNode *end(void){ for(ListNode *p=this; p; p=p->next){ if(p->next==NULL) return p; } }
}; 

void test1(void){
  cout << "=========================================" << endl; 
  cout << "basic ListNode test...." << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  ListNode n1; 
  cout << "static_cast<void *>(&n1): " << static_cast<void *>(&n1) << endl; 
  cout << "n1.dump(): " << endl; 
  n1.dump();
  cout << "n1.dump() end..." << endl; 
//  ListNode n1();
  cout << "=========================================" << endl; 
}

void dumpAll(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  ListNode *n=new ListNode(1, new ListNode(2, new ListNode(3)));
  n->dumpAll();
  cout << "=========================================" << endl; 
}

void getBeginEnd(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  //ListNode *n=new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode n3(3);
  ListNode n2(2, &n3);
  ListNode n1(1, NULL, &n2);
  cout << "n1: " << static_cast<void *>(&n1) << endl; 
  cout << "n2: " << static_cast<void *>(&n2) << endl; 
  cout << "n3: " << static_cast<void *>(&n3) << endl; 
//  cout << "n3->begin(): " << static_cast<void *>(n3.begin()) << endl; 
  cout << "n3.prev: " << static_cast<void *>(n3.prev) << endl;
  cout << "n2.prev: " << static_cast<void *>(n2.prev) << endl;
  cout << "n1.prev: " << n1.prev << endl;
  cout << "NULL: " << static_cast<void *>(NULL) << endl;
  cout << "n3.begin(): " << static_cast<void *>(n3.begin()) << endl;
  cout << "n1.end(): " << static_cast<void *>(n1.end()) << endl;
  cout << "=========================================" << endl; 
}

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

funcTab testFuncTab[]={
  {test1}, 
  {dumpAll}, 
  {getBeginEnd}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}
