#include <iostream>
using namespace std; 
class List {
  class Node {
    int value; 
public: 
    Node *pNext; 
    Node():value(1), pNext(NULL){}
    Node(int _v):value(_v), pNext(NULL){}
    ~Node(){}
  };
public:
  List():_size(0), pHead(NULL), pCurr(NULL){
  }
  ~List(){
    for(Node *pn=pHead; pn; pn=pn->pNext){
      delete pn; 
    }
  }
  void append(int _v){
    Node *pn=new Node(_v); 
    if(pHead){
      pHead=pn; 
    }
    pCurr=pn; 
    _size++;
  }
  int size(void){return _size;}
protected:
  Node *pHead; 
  Node *pCurr; 
  int _size; 
}; 

int main(void){
  List l1;
  cout << l1.size() << endl; 
  l1.append(2);
  cout << l1.size() << endl; 
  return 0; 
}

