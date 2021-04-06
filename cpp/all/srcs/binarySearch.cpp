#include "basic.h"

class Node {
  Node *P; 
  Node *L; 
  Node *R; 
  const char *_name; 
  int val; 
  int layers; 
  int layer; 
  list<string> map_s; 
public: 
  Node():P(NULL), L(NULL), R(NULL), _name("no name"), val(0), layers(1), layer(0){}
  Node(const char *n, int v):P(NULL), L(NULL), R(NULL), _name(n), val(v), layers(1), layer(0){}
  Node(const char *n, int v, Node *a):P(NULL), L(NULL), R(NULL), _name(n), val(v), layers(1), layer(0){ 
    int _layers=1; 
    //this->put(a); 
    compareAppend(this, a, _layers);
  }
  Node(const char *n, int v, vector<Node *>a):P(NULL), L(NULL), R(NULL), _name(n), val(v), layers(1), layer(0){
    for(vector<Node *>::iterator it=a.begin();it!=a.end();it++){
      int _layers=1; 
      //this->put(*it);
      compareAppend(this, *it, _layers);
    }
  }
  ~Node(){}
  void compareAppend(Node *_P, Node *_N, int &_layers){
    if(!_P||!_N) return; 
#if 0
    if(_P->value()>_N->value()){
      _layers++; 
      if(_layers>this->layers) this->layers=_layers; 
      if(_P->L){
        compareAppend(_P->L, _N, _layers);
      }else{
        _P->L=_N; 
	_N->P=_P; 
	_N->layer=_layers; 
      }
    }
    if(_P->value()<_N->value()){
      _layers++; 
      if(_layers>this->layers) this->layers=_layers; 
      if(_P->R){
        compareAppend(_P->R, _N, _layers);
      }else{
        _P->R=_N; 
	_N->P=_P; 
	_N->layer=_layers; 
      }
    }
#else
    Node **ppTmp=NULL; 
    if(_P->value()>_N->value()){
      ppTmp=&(_P->L); 
    }
    if(_P->value()<_N->value()){
      ppTmp=&(_P->R); 
    }
    if(ppTmp){
      _layers++; 
      if(_layers>this->layers) this->layers=_layers; 
      if(*ppTmp){
        compareAppend(*ppTmp, _N, _layers);
      }else{
        *ppTmp=_N; 
        _N->P=_P; 
        _N->layer=_layers; 
      }
    }
#endif
  }
  Node *put(Node *N){ 
    int _layers=0; 
    for(Node *p=this;p;){
      _layers++; 
      if(this->layers<_layers) this->layers=_layers; 
      if(N->val>p->val){
        if(p->R){ p=p->R; continue; }
        else{
	  p->R=N; 
	  N->P=p; 
	}
      }
      if(N->val<p->val){
        if(p->L){ p=p->L; continue; }
        else{ 
	  p->L=N; 
	  N->P=p; 
	}
      }
      break; 
    }
    return this; 
  }
  Node *left(){ return this->L; }
  Node *right(){ return this->R; }
  Node *parent(){ return this->P; }
  int value(void){ return this->val; }
  const char* name(void){ return this->_name ;}
  void rdump2(Node *_l, Node *_r, int _layer, int _no){
    if(_l) rdump1(_l, _layer, _no+1);
    if(_r) rdump1(_r, _layer, _no+2);
  }
  void rdump1(Node *_p, int _layer, int _no){
    cout << "layer: " << _layer 
	 << ", layer: " << _p->layer 
	 << ", no: " << _no 
	 << ", name: " << _p->_name 
	 << ", val: " << _p->val 
	 << endl; 
    if(_p){
      rdump2(_p->L, _p->R, _layer+1, _no);
    }
  }
  void dump(void){
    cout << "layers: " << this->layers << endl; 
    rdump1(this, 0, 1);
#if 0
    Node *p=this; 
    for(int i=0; i<this->layers; i++){
      if(p->L){ p=p->L; continue; }
      if(p->R){ p=p->R; continue; }
      cout << "i: " << i << endl; 
      break; 
    }
#endif
  }
}; 

void test1(void){
  cout << "=========================================" << endl; 
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  /* test case: 100, 200, 50, 30, 70, 80, 40*/
#if 0
  Node *H=new Node("user 1", 100);
  ((Node *)(H->put(new Node("user 2", 200))))->put(new Node("user 3", 50));
  cout << H->left() << endl; 
  cout << "H->right()->value(): " << ((H->right()))->value() << endl; 
  cout << "H->right()->parent()->value(): " << (((H->right()))->parent())->value() << endl; 
#endif
  cout << "Nodes: 100, 200, 50, 30, 70, 80, 300" << endl; 
  Node *H2=new Node("node 1", 100, 
		  vector<Node *>{ 
		    new Node("node 2", 200), 
		    new Node("node 3", 50), 
		    new Node("node 4", 30), 
		    new Node("N5", 70), 
		    new Node("N6", 80), 
		    new Node("N7", 300), 
		    });
  cout << "((H2->right()))->value(): " << ((H2->right()))->value() << endl; 
  cout << "((H2->left())->left())->value(): " << ((H2->left())->left())->value() << endl; 
  cout << "((H2->right())->right())->value(): " << ((H2->right())->right())->value() << endl; 
  cout << "((H2->left())->right())->value(): " << ((H2->left())->right())->value() << endl; 
  H2->dump();
  cout << "=========================================" << endl; 
}

void recursiveType1(const char*, int, int);

void recursiveType2(const char *na, const char *nb, int a, int b, int l){
  printf("%s, %d: layer: %d, %s: %d, %s: %d\n", __FUNCTION__, __LINE__, l, na, a, nb, b);
  fflush(stdout);
  usleep(500000);
  if(a>0) recursiveType1("a", a-1, l+1);
  if(b>0) recursiveType1("b", b-1, l+1);
}

void recursiveType1(const char *n, int s, int l){
  printf("%s, %d: layer: %d, %s: %d\n", __FUNCTION__, __LINE__, l, n, s);
  fflush(stdout);
  usleep(500000);
  if(s>0) recursiveType2("a", "b", s, s, l+1);
}

void test2(void){
  //recursiveType1("start", 5);
  recursiveType2("a", "b", 5, 4, 0);
}

typedef struct funcTab {
  void (*func)(void); 
} funcTab; 

funcTab testFuncTab[]={
  {test1}, 
  {NULL}
}; 

int main(int argc, char *argv[]){
  cout << __FUNCTION__ << ", " << __LINE__ << endl; 
  for(funcTab *p=testFuncTab; p->func; p++){
    p->func();
  }
  return 0; 
}
