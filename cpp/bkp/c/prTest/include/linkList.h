#ifndef __linkList_h__
#define  __linkList_h__
#include "basic.h"
#include "utils.h"
typedef struct node_s node;
struct node_s {
  void *key;
  int keyLen;
  void *data;
  int dataLen; 
  node *prev; 
  node *next; 
};
typedef struct nodes {
  node *ph; 
  node *pcurr; 
} nodes; 
int linkListDummy(void);
#define DEFNODEKEYLEN 10
node* _createNewNode(void);
node* _createNewNodeWithRandKey(void);
void _freeNode(node *pn);
#endif /*__linkList_h__*/

