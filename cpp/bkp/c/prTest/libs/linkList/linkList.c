#include "linkList.h"

int linkListDummy(void){
  printf("%s, %d: \n", __FUNCTION__, __LINE__);
  return 0; 
}

node* _createNewNode(void){
  node *_n; 
  _n=malloc(sizeof(node));
  if(_n){
    memset(_n, 0, sizeof(node));
  }
  return _n; 
}

node* _createNewNodeWithRandKey(void){
  node *_n; 
  _n=_createNewNode();
  if(_n){
    _n->key=malloc(DEFNODEKEYLEN+1);
    if(!_n->key) goto err;
    randString(_n->key, DEFNODEKEYLEN);
  }
  return _n;
err:
  printf("%s, %d: err\n", __FUNCTION__, __LINE__); 
  if(_n){
    if(_n->key) free(_n->key);
    free(_n);
  }
  return NULL; 
}

void _freeNode(node *pn){
  if(pn){
    if(pn->key) free(pn->key);
    if(pn->data) free(pn->data);
  }
}

